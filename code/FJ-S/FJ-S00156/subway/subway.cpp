#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int c = 0, n = 0, m = 0, d = 0, q = 0;
long long w[N];
struct LINE{
	long long ki;
	vector<long long> aij;
	vector<long long> tij;
};
LINE li[N];
//struct POINT{
//	int tn;
//	vector<int> z;
//};
//POINT po[N];
long long dis[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
//		po[i].z.push_back(w[i]);
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &li[i].ki);
		long long cs = 0;
		for (int j = 1; j <= li[i].ki; j++) {
//			po[i].tn++;
			scanf("%lld", &cs);
			li[i].aij.push_back(cs);
			scanf("%lld", &cs);
			li[i].tij.push_back(cs);
//			po[i].z.push_back(cs);
		}
		for (int j = 0; j < li[i].ki; j++) {
			for (int k = 0; k < li[i].ki; k++) {
				dis[li[i].aij[j]][li[i].aij[k]] = min(dis[li[i].aij[j]][li[i].aij[k]], li[i].tij[j] + li[i].tij[k]);
	//			if (i == 1 && j == 1 && k == 2) {
	//				cout << "a";
	//			}
			}
		}
	}
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << dis[i][j] << " ";
//		}
//		cout << "\n";
//	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		long long cx, cy;
		scanf("%lld%lld", &cx, &cy);
		printf("%lld\n", dis[cx][cy] + w[cx] + w[cy]);
	}
	return 0;
}
