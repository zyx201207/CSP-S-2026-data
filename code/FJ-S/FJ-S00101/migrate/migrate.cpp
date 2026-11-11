#include<bits/stdc++.h>
using namespace std;

long long js[100005];
long long c,t;
long long x[10005][10005],d[1000005],n[10000005];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 0;i < t;i++) {
		cin >> n[i] >> d[i];
		for(int j = 0;j < n[i];j++) {
			cin >> x[i][j];
		}
	}
	int s = n[0];
	for(int i = 0;i < s;i++) {
		for(int j = 0;j < n[i];j++) {
			if (x[i][j] + 1 + d[i] == x[i][j+3]) {
				js[i]++;
			}
		}
		s = n[i] + 1;
	}
	for(int i = 0;i < t;i++) {
		cout << js[i] << endl;
	}
	return 0;
}
