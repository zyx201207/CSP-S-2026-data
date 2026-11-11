#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], k[500005], x, y;
struct s{
	vector<pair<int, int>> a;
}line[505];
struct ss{
	vector<pair<int, int>> l;
}lines[500005];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)	scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++){
			int stage, timm;
			scanf("%d %d", &stage, &timm);
			line[i].a.push_back({stage, timm});
			lines[stage].l.push_back({i, timm});
		}
	}
	for (int r = 1; r <= q; r++){
		scanf("%d %d", &x, &y);
		int len[500005];
		for (int i = 1; i <= n; i++){
			len[i] = 1000000005;
		}
				//qidian  zhongdian	bianchang yuanshi
		queue<pair<int, pair<int, pair<int, int>>>> way;
		for (int i = 0; i < lines[x].l.size(); i++){
			int nexttime = lines[x].l[i].second;
			way.push({x, {x, {nexttime, 0}}});
		}
		for (int kkk = 1; kkk <= n-1; kkk++){
			int lastt = way.front().first, noww = way.front().second.first, timee = way.front().second.second.first, ltimee = way.front().second.second.second;
			way.pop();
			len[noww] = min(len[noww], ltimee+timee);
			for (int i = 0; i < lines[noww].l.size(); i++){
				for (int ll = 0; ll < k[lines[noww].l[i].first]; ll++){
					int nextt = line[lines[noww].l[i].first].a[ll].first,
					nexttime = line[lines[noww].l[i].first].a[ll].second;
					if (nextt == lastt || nextt == noww)	continue;
					way.push({noww, {nextt, {nexttime, ltimee+timee}}});
				}
			}
		}
		len[y] += w[x]+w[y];
		cout << len[y] << endl;
	}
	return 0;
}
