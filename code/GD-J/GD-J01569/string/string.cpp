#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long L;
long long ans;
pair<int, char> PIC[N];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> PIC[i].first >> PIC[i].second;
		L += PIC[i].first;
	}
	long long l = 0, r = L + 1, i = 1, j = n;
	while (l < r && i < j) {
		long long leni = PIC[i].first, lenj = PIC[j].first;
		long long len = min(leni, lenj);
		char ci = PIC[i].second, cj = PIC[j].second;
//		cout << leni << " " << lenj << " " << len << " " << ci << " " << cj << " ";
		if (ci != cj) {
			ans += len;
		}
		PIC[i].first -= len;
		PIC[j].first -= len;
		l += len;
		r -= len;
		if (PIC[i].first == 0) i++;
		if (PIC[j].first == 0) j--;
//		cout << ans << " " << l << " " << r << " " << i << " " << j << "\n";
	}
	cout << ans << '\n';
	return 0;
}
