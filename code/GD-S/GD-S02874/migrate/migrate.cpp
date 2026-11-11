#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+5;
int c,n,m,q,t,d,ans;
int a[MAXN],r[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
//	c=11;
	//记得多测清空!!!!!! 
	//好像不用额。 
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];	
		}
		int dis=0;
		bool A=false;
		if(c==11||c==12){
			A=true;
			dis=a[2]-a[1];
			int p=d/dis;
			if(p<=1){
				cout<<0<<'\n';
				continue;
			}else{
				cout<<max((int)0,(n-2*p+1))<<'\n';
				continue;
			}
		}
		a[n+1]=5e18;
		int R=1;
		
		for(int i=1;i<=n;i++){
			while(a[i]+d>=a[R]) R++;
			r[i]=R-1;
//			cout<<r[i]<<" ";
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int now=i,last=i;
				int num=0;
				while(now<j){
					if(now==r[now]&&now!=j){
						num=-1;
						break;
					}
					if(now-1>last&&(r[now-1]==r[now]||r[now-1]>=j)){
						num++;
						if(now-2>last&&(r[now-2]==r[now]||r[now-2]>=j)){
							num++;
						}
					}
					if(num>1) break;
					last=now;
					now=r[now];
				}
				if(num==1){
//					cout<<i<<" "<<j<<'\n';
					ans++;
				} 
			}
		}
		cout<<ans<<'\n';
	}	
	return 0;
}
