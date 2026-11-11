#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q; //测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过以及出行计划数
vector<int> w;
vector<int> k;
vector<int> yb;
vector<int> zb;
vector<pair<int, int>> ans(2005);
vector<pair<int, int>> a(2005);
void findd(int y, int z, int x) {
	int ylenth = a.size();
	yb = {};zb = {};
	for (int i = 0; i < ylenth; i++) {
		if (a[i].first == y) {
			yb.push_back(i);//找出所有开始站点经过线路
		}
		if (a[i].first == z) {
			zb.push_back(i);//找出所有终止站点经过线路
		}
	}
	return ;
}
long long lenthh(){
	int lenth = ans.size();
	long long maxx = 999999999;
	for (int i = 0; i < lenth; i++) {
		if(ans[i].second + ans[i].first < maxx) maxx = ans[i].second + ans[i].first;
	}
	return maxx;
}
bool sameline(int x) {
	int ylenth = yb.size();
	int zlenth = zb.size();
	for (int i = 0; i < ylenth; i++) {
		for (int j = 0; j < zlenth; j++) {
			if (yb[i] / k[x] == zb[i] / k[x]) {
				ans.push_back(make_pair(yb[i],zb[i]));
				return true;
			}
		}
	}
	return false;
}
long long samelines() {
	vector<pair<int, int>> b;b = a;
	for (int i = 0; i < a.size(); i++) {
		for(int j = 0;j < b.size();j++){
			if(b[j].first == a[j].first) return b[j].second == a[j].second;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i <= m; i++) {
		int x;
		cin >> x;
		w.push_back(x);
	}
	for (int i = 0; i <= n; i++) {
		int k1;
		cin >> k1;
		k.push_back(k1);
		for (int j = 0; j < k1; j += 2) {
			int cinn, xinn;
			cin >> cinn >> xinn;
			a[i].first = cinn;
			a[i].second = xinn;//1 5,2 7,4 6   ,  2 3,3 4,5 7
		}
	}
	for (int i = 0; i < q; i++) {
		int start, endd;
		cin >> start >> endd;
		findd(start, endd, i);
		if(sameline(i) == true) cout<<lenthh() + w[start-1] + w[endd-1]<<'\n';
		else{
			cout<<lenthh() + w[start-1] + w[endd-1] + samelines()<<'\n';
		}
	}
	return 0;
}
