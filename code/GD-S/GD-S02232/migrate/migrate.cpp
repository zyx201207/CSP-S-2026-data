#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int c,t,n;
long long d,x[N],f1[N][N],f2[N][N],ans;

void bfs(int s){
	f2[s][s] = 1;
	for(int u = s;u<=n;u++){
		ans+=f2[s][u]==2;
		for(int v = u;x[v]-x[u]<=d;v++){
			if(f1[s][v]>f1[s][u]+1){
				f1[s][v] = f1[s][u]+1;
				f2[s][v] = f2[s][u];
			}
			else if(f1[s][v]==f1[s][u]+1){
				f2[s][v]+=f2[s][u];
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				f1[i][j] = 1e18,f2[i][j] = 0;
			}
		}
		for(int i = 1;i<=n;i++){
			cin>>x[i];
		}
		for(int i = 1;i<=n;i++){
			bfs(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

