#include <iostream>
#include <set>
#include <vector>
#include <fstream>
using namespace std;
int a,t,w[1002],k;
long long P[1502][1502];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	for(int i = 1;i<= n + 1000;i++){
		if(i > m and i <= 1000) continue;
		for(int j = 1;j<=n+1000;j++){
			if(j > m and j <= 1000) continue;
			if(i!=j) P[i][j] = 1000000000002;
		}
	}
	for(int i = 1;i<=n;i++){
		cin >> k;
		for(int j = 1;j<=k;j++){
			cin >> a >> t;
			P[1000 + i][a] = t;
			P[a][1000+i] = t;
		}
	}
	
	for(int i = 1;i<=n+1000;i++){
		if(i > m and i <= 1000) continue;
		for(int j = 1;j<=n + 1000;j++){
			if(i == j) continue;
			if(j > m and j <= 1000) continue;
			for(int k = 1;k<=n+1000;k++){
				if(i == k or j == k) continue;
				if(k > m and k <= 1000) continue;
				P[i][j] = min(P[i][j],P[i][k] + P[k][j]);
				if(P[i][j] < P[j][i]){
					P[j][i] = P[i][j];
				}
			}
		}
	}
	int st,ed,tm;
	while(q--){
		cin >> st >> ed;
		cout << P[st][ed] + w[st] + w[ed] << endl;
	}
	return 0;
}
