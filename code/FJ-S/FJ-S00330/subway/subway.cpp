#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >>m >>d >>q;
	
	vector<int> w(m + 50);
	vector<vector<pair<int,int>>> k(n + 50);
	for(int i = 1;i <= m;i ++) {
		cin >> w[i];
	}
	
	int tk;
	for (int i = 1;i <= n;i ++) {
		cin >> tk;
		for(int i = 1;i <= n;i ++) {
			k[i].resize(tk + 50);
		}
		for (int j = 1;j <= tk;j ++) {
			cin >> k[i][j].first >> k[i][j].second;
		}
	}
	int xr,yr;
	for(int i = 1;i <= q;i ++) {
		cin >> xr >> yr;
		if(n == 1) {
			cout << w[xr] + w[yr] << endl;
		} else if(n == 2) {
			int same = 0,xoy;
			for(int i = 1;i <= k[1].size();i ++) {
				if(k[1][i].first == xr){
					same ++;
					xoy = 1;
				} 
				if(k[1][i].first == yr) same ++;
			}
			if(same == 0 || same == 2) {
				cout << w[xr] + w[yr] + (xoy?(k[1][xr].second + k[1][yr].second):(k[2][xr].second + k[2][yr].second)) << endl;
			} else {
				bool flag = 0;
				for (int i = 1;i <= k[1].size();i ++) {
					for(int j = 1;j <= k[2].size();j ++){
						if(k[1][i].first == k[2][j].first) {
							cout << k[1][i].second + k[2][j].second + 
								w[xr] + w[yr] +
								(xoy?(k[1][xr].second + k[2][yr].second):(k[2][xr].second + k[1][yr].second))
								<< endl;
							//cout << i << " " << j << endl;
							//cout << k[1][i].second << " " << k[2][j].second << " " << w[xr] << " " << w[yr] << " " << k[1][xr].second <<" " << k[2][yr].second;
							flag = 1;
							break;
						}
					}
					if(flag) break;
				}
			}
		} else if(n == 3) {
			int xrpos = 0,yrpos = 0;
			for(int i = 1;i = 3;i ++) {
				for (int j = 1;j <= k[i].size();j ++) {
					if(k[i][j].first == xr) {
						xrpos = i;
					}
					if(k[i][j].first == yr) {
						yrpos = i;
					}
				}
			}
			vector<pair<pair<int,int>,int>> chgs(m+50);
			for(int p = 1;p <= 3;p ++){
				for (int q = i + 1;q <= 3;q ++){
					for (int i = 1;i <= k[p].size();i ++) {
						for (int j = 1;j <= k[q].size();j ++) {
							if(k[p][i].first == k[q][j].second) {
								chgs.push_back({{i,j},k[p][i].second+k[q][j].second});
							}
						}
					}
				}
			}
			int min1t2 = 1e9, min2t3 = 1e9, min1t3 = 1e9;
			for(auto i : chgs) {
				if(i.first.first == 1 && i.first.second == 2 &&i.second < min1t2) {
					min1t2 = i.second;
				}
				if(i.first.first == 1 && i.first.second == 3 &&i.second < min1t3) {
					min1t3 = i.second;
				}
				if(i.first.first == 2 && i.first.second == 3 &&i.second < min2t3) {
					min2t3 = i.second;
				}
			}
			if(xrpos + yrpos == 3) {
				cout << min(min1t2, min1t3+min2t3) + w[xr] + w[yr] + k[xrpos][xr].second + k[yrpos][yr].second;
			} else if(xrpos + yrpos == 4) {
				cout << min(min1t3, min1t2+min2t3) + w[xr] + w[yr] + k[xrpos][xr].second + k[yrpos][yr].second;
			} else {
				cout << min(min2t3, min1t2+min1t3) + w[xr] + w[yr]+ k[xrpos][xr].second + k[yrpos][yr].second;
			}
		}
	}
	
}
