#include <bits/stdc++.h>

int c, n, m, d, q;
int w[1005][1005];
int ways[100005][2];
int sub[1005];
int k[5005];


int main(){
	std::freopen("subway.in", "r", stdin);
	std::freopen("subway.out", "w", stdout);
	std::cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; ++i) std::cin >> sub[i];
	for(int i=1; i<=n; ++i){
		int line[1005], time[1005];
		std::cin >> k[i];
		for(int j=1; j<=k[i]; ++j){
			std::cin >> line[j] >> time[j];
		}
	}
	//	for(int j=1; j<=k; ++j){
	//		for(int j2=1; j2<=k; ++j2){
	//			if(!w[line[j]][line[j2]]) w[line[j]][line[j2]] = time[line[j2]]+; 
	//		}
	//	}
}
