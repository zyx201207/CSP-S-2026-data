#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int c,t;
ll n,d,x[N];
ll ans;
int q[N],top;
int check(int l,int r){
	int sum=0,top=1; //先找最小路长度
	for(int i=l+1;i<=r;i++){
		if(sum+(x[i]-x[i-1])>d){
			sum=0; q[top++]=i-1;
		}
		sum+=(x[i]-x[i-1]);
	}
//	cout<<top<<endl;// 找第二条路 //可以拿2点 
//	for(int i=1;i<top;i++){
//		cout<<q[i]<<" h ";
//	}cout<<endl;
	return top;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<4){
			cout<<0<<endl;
		}
		if(n==4){
			int ch=check(1,4);
			if(ch==1||ch==3) cout<<0<<endl;
			else{
				int a1=x[3]-x[1],a2=x[4]-x[2];
				if(a1<=d&&a2<=d){
					cout<<1<<endl;
				}
			}
			continue;
		}
		if(n==5){
			ans=0; 
			int ch=check(1,4);
			if(!(ch==1||ch==3)){
				int a1=x[3]-x[1],a2=x[4]-x[2];
				if(a1<=d&&a2<=d) ans++;
			}
			ch=check(2,5);
			if(!(ch==1||ch==3)){
				int a1=x[4]-x[2],a2=x[5]-x[3];
				if(a1<=d&&a2<=d) ans++;
			}
			ch=check(1,5);
			if(!(ch==1||ch==4)){
				if(ch==2){
					int cnt=0;
					if(x[4]-x[1]<=d&&x[5]-x[4]<=d) cnt++;
					if(x[3]-x[1]<=d&&x[5]-x[3]<=d) cnt++;
					if(x[2]-x[1]<=d&&x[5]-x[2]<=d) cnt++;
					if(cnt==2) ans++;
				}else if(ch==3){
					int cnt=0;
					if(x[3]-x[1]<=d&&x[4]-x[3]<=d&&x[5]-x[4]<=d) cnt++;
					if(x[2]-x[1]<=d&&x[4]-x[2]<=d&&x[5]-x[4]<=d) cnt++;
					if(x[2]-x[1]<=d&&x[3]-x[2]<=d&&x[5]-x[3]<=d) cnt++;
					if(cnt==2) ans++;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
//				cout<<"ij="<<i<<' '<<j<<endl;
//				if(check(i,j)) ans++;
//				cout<<check(i,j)<<endl;
				
			}
		}
		cout<<ans<<endl;
//		cout<<endl;
	}
}


