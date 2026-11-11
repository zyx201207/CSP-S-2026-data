#include<bits/stdc++.h>
#define int long long
using namespace std;
vector< pair<int,char> > v, vq, vh;
int mid, ans, n;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		int a;
		char b;
		cin >> a >> b;
		mid += a;
		if(i != 0 && v[v.size() - 1].second == b) v[v.size() - 1].first += a;
		else v.push_back({a, b});
	}
	if(v.size() == 0) {
		cout << 0;
		return 0;
	}
	if(mid & 1) {
		mid = (mid + 1) / 2;
		bool flag = false;
		for(int i = 0 ; i < v.size() ; i++) {
			if(flag){
				vh.push_back({v[i].first, v[i].second});
				continue;
			}
			if(mid <= v[i].first) {
				if(mid != 1) vq.push_back({mid - 1, v[i].second});
				if(v[i].first != mid) vh.push_back({v[i].first - mid, v[i].second});
				flag = true;
				mid = 0;
			}
			else {
				mid -= v[i].first;
				vq.push_back({v[i].first, v[i].second});
			}
		}
	}
	else {
		mid /= 2;
		bool flag = false;
		for(int i = 0 ; i < v.size() ; i++) {
			int x = v[i].first;
			char y = v[i].second;
			if(flag) {
				vh.push_back({x, y});
				continue;
			}
			if(mid <= x) {
				if(mid != 0) vq.push_back({mid, y});
				if(v[i].first != mid) vh.push_back({x - mid, y});
				flag = true;
				mid = 0;
			}
			else {
				mid -= v[i].first;
				vq.push_back({x, y});
			}
		}
	}
	pair<int, char> x = vq[0], y = vh[vh.size() - 1];
	while(vq.size() && vh.size()) {
		if(x.second != y.second) {
			ans += min(x.first, y.first);
			if(x.first > y.first) {
				x.first -= y.first;
				vh.pop_back();
				y = vh[vh.size() - 1];
			}
			else if (x.first < y.first) {
				y.first -= x.first;
				vq.erase(v.begin());
				x = vq[0];
			}else {
				vh.pop_back();
				y = vh[vh.size() - 1];
				vq.erase(v.begin());
				x = vq[0];
			}
		}else {
			if(x.first > y.first) {
				x.first -= y.first;
				vh.pop_back();
				y = vh[vh.size() - 1];
			}
			else if (x.first < y.first) {
				y.first -= x.first;
				vq.erase(v.begin());
				x = vq[0];
			}else{
				vh.pop_back();
				y = vh[vh.size() - 1];
				vq.erase(v.begin());
				x = vq[0];
			}
		}
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
