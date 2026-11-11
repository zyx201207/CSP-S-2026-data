#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
vector<pair<int, pair<int, char> > > a, b;
char gjr[200005];
int len[200005], sum;
bool cmp(pair<int, pair<int, char> > x, pair<int, pair<int, char> > y) {
	return x.first < y.first;
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> len[i] >> gjr[i];
		sum += len[i]; 
	}
	int answ = sum / 2, now = 1;
	for(int i = 1;i <= n;i++) {
		if(now <= answ && now + len[i] - 1 <= answ) {
			a.push_back({now, {now + len[i] - 1, gjr[i]}});
			now += len[i];
		} else if(now <= answ && now + len[i] - 1 > answ) {
			a.push_back({now, {answ, gjr[i]}});
			if(sum % 2) b.push_back({sum - (now + len[i] - 1) + 1, {sum - (answ + 2) + 1, gjr[i]}});
			else b.push_back({sum - (now + len[i] - 1) + 1, {sum - (answ + 1) + 1, gjr[i]}});
			now += len[i];
		} else {
			b.push_back({sum - (now + len[i] - 1) + 1, {sum - now + 1, gjr[i]}});
			//if(i == n) cout << sum - (now + len[i] - 1) + 1 << " " << sum - now + 1 << " " << gjr[i] << "\n";
			now += len[i];
		}
	}
	//if(now != sum) b.push_back({1, {sum - now + 1, gjr[n]}});
	sort(b.begin(), b.end(), cmp);
	int nowa = 0, nowb = 0;
	while(a[nowa].second.first != sum / 2 || b[nowb].second.first != sum / 2) {
		if(a[nowa].second.second == b[nowb].second.second) answ -= min(a[nowa].second.first, b[nowb].second.first) - max(a[nowa].first, b[nowb].first) + 1;
		//cout << a[nowa].first << " " << a[nowa].second.first << " " << a[nowa].second.second << " " << b[nowb].first << " " << b[nowb].second.first << " " << b[nowb].second.second << " " << answ << "\n";
		if(a[nowa].second.first < b[nowb].second.first) nowa++;
		else if(a[nowa].second.first == b[nowb].second.first) {
			nowa++;
			nowb++;
		} else nowb++;
	} 
	if(a[nowa].second.second == b[nowb].second.second) answ -= min(a[nowa].second.first, b[nowb].second.first) - max(a[nowa].first, b[nowb].first) + 1;
	cout << answ;
	return 0;
}
