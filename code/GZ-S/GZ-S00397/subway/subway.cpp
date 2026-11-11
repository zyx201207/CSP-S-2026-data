//GZ-S00397 毕节梁才学校 王艺杰 
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010],t[100010][30],dis[510][510];

vector<int> step[500010];
void work(){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n ;j++){
			dis[i][j]=0x8f8f8f8f;
		}
	}
	for (int i=1; i<=m; i++){
		for (int j=0;j<step[i].size();j++){
			for (int k=0;k<step[i].size(); k++){
				dis[step[i][j]][step[i][k]]=min(dis[step[i][j]][step[i][k]],t[i][step[i][j]]+t[i][step[i][k]]);
				if (j==k){
					dis[step[i][j]][step[i][k]]=0;
				}
			}
		}
	}
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c>> n>>m>>d>>q;
	for (int i=1; i<=m; i++){
		cin >> w[i];
	}
	for (int i=1; i<=n; i++){
		int k;
		cin >> k;
		for (int j=1; j<=k; j++){
			int a;
			int x;
			cin >> a >> x;
//			cout << a<<","<<i<< " "<<x<<endl;
			t[a][i]=x;
			step[a].push_back(i);
		}
	}
	work();
	for (int i=1; i<=q; i++){
		long long mi=0x8f8f8f8f;
		int x,y;
		cin >> x >> y;
		for (int j=0; j<step[x].size(); j++){
			for (int k=0; k<step[y].size(); k++){
				mi=min(mi,dis[step[x][j]][step[y][k]]+t[x][step[x][j]]+t[y][step[y][k]]+w[x]+w[y]);
//				cout << dis[step[x][j]][step[y][k]]<<" "<<t[x][step[x][j]]<<" "<<t[y][step[y][k]]<<" "<<w[x]<<" "<<w[y];
			}
		}
		cout <<mi<< endl;
	}

	
	return 0;
}
