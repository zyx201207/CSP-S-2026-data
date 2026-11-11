#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e9+10,NINF=-1e9-10,N=10050;
ll c,t,n,d,x[N],dis[N][N],v[N][N],o=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				v[i][j]=0;
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				if(i==j)dis[i][j]=dis[j][i]=0;
				else dis[i][j]=dis[j][i]=INF;
			}
		}
		
		
		for(ll i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1&&x[i]-x[i-1]<=d){
				dis[i-1][i]=x[i]-x[i-1];
				v[i-1][i]++;
			}
		}
		
		
		for(ll k=1;k<=n;k++){
			for(ll i=1;i<=n;i++){
				for(ll j=i;j<=n;j++){
					if(dis[i][j]==dis[i][k]+dis[k][j])v[i][j]++;
					else v[i][j]=1;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<=n;i++){
			for(ll j=i;j<=n;j++){
				if(v[i][j]==2&&i!=j)ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
