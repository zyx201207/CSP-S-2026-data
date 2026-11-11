#include <iostream>
#include <fstream>

using namespace std;

int n,i,j;
long long a[20010],ans;
char c[20010];
string s;

int main (void) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		cin >> c[i];
	}
	i = 1;
	j = n;
	while (i <= j) {
		if (a[i] > a[j]) {
			if (c[i] != c[j]) ans += a[j];
			a[i] -= a[j];
			a[j] = 0;
			j--;
		} else if (a[i] < a[j]) {
			if (c[i] != c[j]) ans += a[i];
			a[j] -= a[i];
			a[i] = 0;
			i++;
		} else if (a[i] == a[j]) {
			if (c[i] != c[j]) ans += a[i];
			a[i] = a[j] = 0;
			i++;
			j--;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
