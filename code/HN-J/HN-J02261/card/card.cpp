#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], flag[300005], t[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i >= 1; i--)
		if (flag[a[i]] == 0)
			flag[a[i]] = i;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++){
			t[a[j]]++;
			if (flag[a[j]] != j)
				j = flag[a[j]];
		}
	for (int i = 1; i <= m; i++)
		cout << t[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
