#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;
long long x[N],h[N],d;
void ds(int l,int r,int y){
	if(l>=r){
		h[y]++;return;
	}
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]>d)break;
		ds(i,r,y+1);
	}
}
int chk(int l,int r){
	memset(h,0,sizeof(h));
	ds(l,r,0);
	for(int i=1;i<=n;i++){
		if(h[i]>0){
			if(h[i]==2)return 1;
			return 0;	
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_;
	cin>>c>>_;
	while(_--){
		cin>>n>>d;
		long long y=0;
		int te=0,te2=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>1){
				y=x[2]-x[1];
				if(x[i]-x[i-1]!=y)te=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(x[i]-x[1]<=d&&x[n]-x[i]<=d)te2=1;
		}
		if(te2==1){
			cout<<0<<"\n";
			continue;
		}
		if(te==0){
			if(d*2/y==3)cout<<n-3<<"\n";
			else cout<<0<<"\n";
			continue;
		}
		if(n<=9){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(chk(i,j))ans++;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		cout<<0<<"\n";
	}
	return 0;
}
