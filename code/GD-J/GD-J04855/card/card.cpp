#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> a, mark, nxpos, ex;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	a.resize(n+1), mark.resize(m+1), ex.resize(m+1), nxpos.resize(n+1);
	for (int i = 0;i <(int)ex.size();i++) {
		ex[i]=-1;
	}
	for (int i = 0;i <(int)mark.size();i++) {
		mark[i]=0;
	}
	for (int i = 0;i <(int)nxpos.size();i++) {
		nxpos[i]=-1;
	}
	for (int  i = 1; i <= n; i++) {
		cin >> a[i];
		if (ex[a[i]] != -1) {//上一个a[i]的坐标 
			nxpos[ex[a[i]]] = i;//下一个同类的坐标 
		}
		ex[a[i]] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n;) {
			if (nxpos[j]!=-1) {
				j = nxpos[j];
			}
			else {
				mark[a[j]]++;
				j++;
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		cout << mark[i] << ' ';
	}
	
	return 0;
}
