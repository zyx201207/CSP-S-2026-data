#include<bits/stdc++.h>
using namespace std;
const int N = 500;
const int M = 5000; 
long long w[N];
long long t[N][N];
long long aT[N][N];
int k[N];
vector<int> a[N];  //第i个线路所掌控的地铁站 
vector<int> b[M]; //第i个地铁站属于的路线 
int c, n, m, d, q;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	
	//DEBUG
	//DEBUG
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		for(int j = 1; j <= k[i]; j++){
			int aij;
			scanf("%d", &aij);
			a[i].push_back(aij);
			b[aij].push_back(i);
			long long tTmp;
			scanf("%lld", &tTmp);
			t[aij][i] = tTmp;
		}
	}
	
	memset(aT, 0x3f, sizeof(aT));
	
	//DEBUG
	cout << "DEBUG1\n";
	//DEBUG
	
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			for(int l = 0; l < a[i].size(); l++){
				for(int k = 0; k < a[j].size(); k++){
					//DEBUG
					cout << "DEBUG2\n";
					//DEBUG
					if(a[i][l] == a[j][k]){
						aT[i][j] = min(aT[i][j], t[a[i][l]][i] + t[a[i][l]][j]);
						aT[j][i] = min(aT[j][i], t[a[i][l]][i] + t[a[i][l]][j]);
					}
				}
			}
		}
	}
	
	for(int i = 1; i <= q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		long long ans = INT_MAX;
		for(int j = 0; j < b[x].size(); j++){
			for(int k = 0; k < b[y].size(); k++){
					//DEBUG
					cout << "DEBUG3\n";
					//DEBUG
				ans = min(ans, aT[b[i][x]][b[j][y]]);
			}
		}
		ans += w[x] + w[y];
		printf("%lld\n", ans);
	}
	
	return 0;
}
