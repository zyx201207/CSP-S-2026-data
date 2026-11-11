#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=305;
const ll M=2e6+5;
ll dis[N][N],a[M],cnt[N][N];
ll n,d,T,IDT;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>IDT>>T;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dis[i][j]=1e18;
				if(abs(a[i]-a[j])<=d){
					cnt[i][j]=1;
					dis[i][j]=1;
				}
				cnt[i][j]=0;
			}
			dis[i][i]=0;
			cnt[i][i]=1;
		}
//		for(ll k=1;k<=n;k++){
//			for(ll i=1;i<=n;i++){
//				if(i==k) continue;
//				if(dis[i][k]==1000000000000000000) continue;
//				for(ll j=1;j<=n;j++){
//					if(k==j||i==j) continue;
//					if(abs(a[i]-a[k])<=d&&abs(a[j]-a[k])<=d){
//						if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]++;
//						else if(dis[i][k]+dis[k][j]<dis[i][j]){
//							cnt[i][j]=1;
//							dis[i][j]=dis[i][k]+dis[k][j];
//						}
//					}
//				}
//			}
//		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(i==j) continue;
				for(ll k=i+1;k<j;k++){
					if(abs(a[i]-a[k])<=d&&abs(a[j]-a[k])<=d){
						if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]++;
						if(dis[i][k]+dis[k][j]<dis[i][j]){
							cnt[i][j]=1;
							dis[i][j]=dis[i][k]+dis[k][j];
						}
					}
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
//				cout<<dis[i][j]<<" ";
				if(cnt[i][j]==2) ans++;
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
