#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,m;
int a[2000006];
int nx[2000006];
int qz[2000006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			qz[i]=1;
		}
		for(int i=1;i<=n;i++){
			nx[i]=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(nx[i]-i==0)continue;
			if(nx[i]-i==1){
				qz[i+1]+=qz[i];
				continue;
			}
			if(nx[i]-i==2){
				if(nx[nx[i]-1]-nx[i]<=0)continue;
				ans+=(nx[nx[i]-1]-nx[i])*qz[i];
				int now=nx[nx[i]-1];
				while(now+1<=n&&nx[now]!=now){
					if(now+1>nx[now-1]){
						ans+=(nx[now]-now)*qz[i];
						now=nx[now];
					}else{
						break;
					}
				}
			}else{
				if(nx[nx[i]-1]-nx[nx[i]-2]<=0)continue;
				ans+=(nx[nx[i]-1]-nx[nx[i]-2])*qz[i];
				int now=nx[nx[i]-1];
				while(now+1<=n&&nx[now]!=now){
					if(now+1>nx[now-1]){
						ans+=(nx[now]-now)*qz[i];
						now=nx[now];
					}else{
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
