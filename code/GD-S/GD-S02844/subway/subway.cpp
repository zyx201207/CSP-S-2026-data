#include <bits/stdc++.h>
using namespace std;
int c;
int n;
int m;
int d;
int q;
long long taiting[500005];
struct zcm{
	int kfc;
	long long time;
};
vector<zcm> zt[505];
vector<int> can[500005];
bool use[505];
bool use2[500005];
int yii;
long long find1(int xiii);
long long find(int xii){
	if(xii == yii){
		return 0;
	}
	long long ans = 0x3f3f3f3f3f3f3f3f;
	long long now = 0ll;
	for(auto i : can[xii]){
		if(!use[i]){
			use[i] = true;
			now = find1(i);
			for(auto j : zt[i]){
				if(j.kfc == xii){
					now += j.time;
					break;
				}
			}
			use[i] = false;
			ans = min(now, ans);
		}
	}
	return ans;
}
long long find1(int xiii){
	long long ans = 0x3f3f3f3f3f3f3f3f;
	long long now = 0;
	for(auto i : zt[xiii]){
		if(!use2[i.kfc]){
			use2[i.kfc] = true;
			now = find(i.kfc);
			now += i.time;
			use2[i.kfc] = false;
			ans = min(now, ans);
		}
	}
	return ans;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> taiting[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int x;
			long long y;
			cin >> x >> y;
			zcm zcm1;
			zcm1.kfc = x;
			zcm1.time = y;
			zt[i].push_back(zcm1);
			can[x].push_back(i);
		}
	}
	for(int i = 1; i <= q; i++){
		int x;
		cin >> x >> yii;
		use2[x] = true;
		cout << find(x) + taiting[x] + taiting[yii] << endl;
		use2[x] = false;
	}
	return 0;
}
