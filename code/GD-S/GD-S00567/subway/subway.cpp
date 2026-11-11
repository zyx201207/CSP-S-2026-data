#include <bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=2e4+5;
typedef long long ll;
ll c,n,m,d,q;
ll w[maxm];
ll line[maxn][maxm],dist[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	memset(dist,0x3f3f3f3f,sizeof(dist));
	for (int i=1;i<=m;i++){
		cin >> w[i];
		dist[i][i]=0;
	}
	for (int i=1;i<=n;i++){
		int k;
		cin >> k;
		for (int j=1;j<=k;j++){
			int st,t;
			cin >> st >> t;
			line[i][st]=t;
		}
	}
	for (int i=1;i<=m;i++){
		for (int l=1;l<=n;l++){
			if (!(line[l][i])) 
				continue;
			for (int j=1;j<=m;j++){
				if (!(line[l][j])||i==j)	
					continue;
				dist[i][j]=w[i]+w[j]+line[l][i]+line[l][j]; 
			}
		}
	}
	for (int i=1;i<=m;i++){
		for (int l=1;l<=n;l++){
			if (!(line[l][i]))
				continue;
			for (int k=1;k<=m;k++){
				if (i==k)
					continue;
				for (int j=1;j<=n;j++){
					if (i==j||j==k)
						continue;
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]-w[k]+line[l][k]);
				}
			}
		}
	}
	while (q--){
		int u,v;
		cin >> u >> v;
		cout << dist[u][v] << '\n';
	}
	return 0;
} 
