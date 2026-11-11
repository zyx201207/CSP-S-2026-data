#include<bits/stdc++.h>
using namespace std;

struct way {
	int start;
	int finish;
};

struct couldset {
	int to = 0;
	int need = 0;
	int cnt = 0;
};

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;

	int w[500005] = {};
	int book[500005] = {};
	way k[505] = {};
	couldset could[5000005][505] = {};

	for(int i = 0; i < m; ++i) {
		cin >> w[i];
	}


	for(int i = 0; i < n; ++i) {
		int space;
		cin >> space;

		int need1,need2;
		cin >> k[i].start >> need1 >> k[i].finish >> need2;

		for(int j = 0; j < m; ++j) {
			if(k[i].start == j) {
				could[j][++cnt].to = k[i].finish;
				could[j][+cnt].need = need1;
			}
			if(k[i].finish == j) {
				could[j].to = k[i].start;
				could[j].need = need2;
			}
		}

	}

	int begin_station,end_station;
	cin >> begin_station >> end_station;

	int cnt = 0;
	cnt += w[begin_station];
	cnt += w[end_station];

	int minnum = 2147483647;
	cnt += 2*could[1][1].need*3;
	cout << cnt;

	return 0;
}