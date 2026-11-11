#include<bits/stdc++.h>
using namespace std;
#define int long long

int dis[2005][2005];
int t[1005],x[1005];
int w[1005];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	memset(dis,0x1f,sizeof(dis));
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> t[j] >> x[j];
		}
		for(int j=1;j<=k;j++){
			for(int j1=j;j1<=k;j1++){
				dis[t[j]][t[j1]]=dis[t[j1]][t[j]]=x[j]+x[j1];
			}
		}
	}
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	while(q--){
		int s,e;
		cin >> s >> e;
		cout << dis[s][e]+w[s]+w[e] << endl;
	}
	return 0;
}
//FUCK CCF
