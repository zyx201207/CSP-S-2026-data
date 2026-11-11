#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,long long>
#define pb push_back
const int maxn=2e6+5;
ll dis[maxn];
ll f[maxn],sum[maxn];
ll x[maxn];
int c,t,n;
ll d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n<=300){
			ll ans=0;
			for(int i=1;i<=n;i++){
				dis[i]=0;f[i]=1;
				for(int j=i+1;j<=n;j++){
					dis[j]=1e9;f[j]=0;
					for(int k=i;k<j;k++){
						if(x[k]+d>=x[j]){
							if(dis[j]==1e9||dis[j]==dis[k]+1){
								dis[j]=dis[k]+1;
								f[j]+=f[k];
							}else break;
						}
					}
					if(dis[j]==1e9)break;
					if(f[j]==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}else 
		if(n<=5000){
			ll ans=0;
			for(int i=1;i<=n;i++){
				dis[i]=0;f[i]=1;sum[i]=1;
				sum[i-1]=0;
				for(int j=i+1;j<=n;j++){
					dis[j]=1e9;f[j]=0;
					int l=lower_bound(x+i,x+j,x[j]-d)-x;
					if(l==j)break;
					dis[j]=dis[l]+1;
					int r=(upper_bound(dis+i,dis+j,dis[l])-dis)-1;
					f[j]=sum[r]-sum[l-1];
					if(f[j]==2)ans++;
					sum[j]=sum[j-1]+f[j];
				}
			}
			cout<<ans<<"\n";
		}else{
			int p=d/(x[2]-x[1]);
			if(p==1||p==0){
				cout<<0<<"\n";
			}else{
				ll ans=0;
				for(int i=1;i<=n;i++){
					if(i+p+p-1<=n){
						ans++;
					}
				}
				cout<<ans<<"\n";	
			}
		}
	}
}
