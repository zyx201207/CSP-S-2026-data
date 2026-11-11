#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10,M=310;
const int inf=2e9;
ll x[N];
int dis[M][M],f[M][M];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=inf;
			}
			dis[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) dis[i][j]=1; 
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]==inf||dis[k][j]==inf) continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		int ans=0;
		for(int st=1;st<=n;st++){
			memset(f,0,sizeof(f));
			f[st][0]=1;
			for(int i=st;i<=n;i++){
				for(int j=st;j<=i;j++){
					int k=dis[st][i];
					if(k>0&&x[i]-x[j]<=d) f[i][k]+=f[j][k-1];
				}
			}
			for(int i=st;i<=n;i++){
				int k=dis[st][i];
				if(f[i][k]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
0 1
6 2
-4 -3 -2 -1 3 6

*/

