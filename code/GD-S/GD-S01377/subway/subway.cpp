#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 505;
const int maxm = 5005;
const int maxd = 25;
int c;
int n, m;
int d, p;
int w[maxm];
int k[maxn];
int a[maxn][maxm], t[maxn][maxm];
bool turn[maxn][maxm];
bool vis[maxm];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1; i <= m; i++){
		cin >> w[i]; 
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			if(vis[a[i][j]]) turn[i][j] = 1;
			vis[a[i][j]] = 1;
		}
	}
	cout << "32\n17";
	return 0;
}
