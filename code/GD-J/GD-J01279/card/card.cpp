#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], cnt[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int>x;
	vector<int>y;
	for(int i = 1; i <= n; i++){
		x.clear();
		for(int j = i; j <= n; j++){
			y.clear();
			for(int s = 0; s < x.size(); s++){
				if(x[s] == a[j]){
					x.clear();
					for(int k = 0 ;k < y.size(); k++)
						x.push_back(y[k]);
					break;
				}
				y.push_back(x[s]);
			}
			x.push_back(a[j]);
		}
		for(int j = 0; j < x.size(); j++)
			cnt[x[j]]++;
	}
	for(int i = 1; i <= m; i++)
		cout << cnt[i] << " ";
	
	return 0;
}
