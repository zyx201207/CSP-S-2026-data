#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MaxN=1e5+100;
const ll inf=1e18;

int c,t,n;
ll d;
ll x[MaxN];

int main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			int pos=0;
			for(int i=1;i<=n;i++){
				if(x[i]-x[1]<=d)pos=i;
			}
			ll ans=0;
			for(int l=1,r=1;r<=n;r++){
				while(l<=r&&x[r]-x[l]>d)l++;
				if(r>pos){
					if(pos-l+1==2)ans+=l-1;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		vector<vector<ll> > f(n+10,vector<ll>(n+10,0)),dis(n+10,vector<ll>(n+10,inf));
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			f[i][i]=1; 
		}
		for(int len=1;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				for(int k=i;k<=j;k++){
					if(x[k]-x[i]>d)break;
					if(dis[k][j]+1<dis[i][j]){
						dis[i][j]=dis[k][j]+1;
						f[i][j]=f[k][j];
					}else if(dis[k][j]+1==dis[i][j])f[i][j]+=f[k][j];
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(f[i][j]==2)ans++;
			}
		}
		for(int i=1;i<=n;i++){
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
