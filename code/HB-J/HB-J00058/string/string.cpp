#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
pair<int, char> a[N];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %c", &a[i].first, &a[i].second);
	long long ans = 0, sum1 = a[1].first, sum2 = a[n].first;
	bool b = sum1 > sum2;
	for (int l = 1, r = n; l < r; ){
		if (sum1 > sum2){
			ans += (sum2 - (sum1 - a[l].first)) * (a[r].second != a[l].second);
			while (sum1 > sum2){
				sum2 += a[--r].first;
				if (sum1 <= sum2)
					break;
				ans += a[r].first * (a[r].second != a[l].second);
			}
		}
		else{
			ans += (sum1 - (sum2 - a[r].first)) * (a[r].second != a[l].second);
			while (sum1 <= sum2){
				sum1 += a[++l].first;
				if (sum1 > sum2)
					break;
				ans += a[l].first * (a[r].second != a[l].second);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}