#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , q;
int w[500010];
struct qll{
	int dl;
	long long dj;
};
vector<qll> a[500010];
long long lj[510][510][510];
long long min(long long a , long long b){
	if(a < b) return a;
	return b;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	for(int l = 0; l <= n; l++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) lj[l][i][j] = 0;
				else lj[l][i][j] = 1e18;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++){
			int x , y;
			scanf("%d%d", &x, &y);
			a[x].push_back({i,y});
		}
	}
	for(int l = 1; l <= m; l++){
		for(int i = 0; i <= a[l].size()-1; i++){
			for(int j = i+1; j <= a[l].size()-1; j++){
				lj[0][a[l][i].dl][a[l][j].dl] = min(lj[0][a[l][i].dl][a[l][j].dl],a[l][i].dj+a[l][j].dj);
				lj[0][a[l][j].dl][a[l][i].dl] = min(lj[0][a[l][j].dl][a[l][i].dl],a[l][i].dj+a[l][j].dj);
			}
		}
	}
	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << lj[0][i][j] << " ";
		}cout << endl;
	}cout << endl;*/
	for(int l = 1; l <= n; l++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				lj[l][i][j] = min(lj[l-1][i][j],lj[l-1][i][l]+lj[l-1][l][j]);
				//cout << lj[l][i][j] << " ";
			}//cout << endl;
		}//cout << endl;
	}
	while(q--){
		int x , y;
		scanf("%d%d", &x, &y);
		long long mn = 1e18;
		for(int i = 0; i <= a[x].size()-1; i++){
			for(int j = 0; j <= a[y].size()-1; j++){
				mn = min(mn,lj[n][a[x][i].dl][a[y][j].dl]+w[x]+w[y]+a[x][i].dj+a[y][j].dj);
			}
		}
		printf("%lld\n", mn);
	}/**/
	return 0;
}
