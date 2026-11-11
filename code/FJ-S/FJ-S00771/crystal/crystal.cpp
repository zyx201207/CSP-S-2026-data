#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 10;

int n;
LL m, a[N];
LL preS[N];

int Ans;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i++) preS[i] = preS[i - 1] + a[i];
	
	for (int i = 2; i <= n; i++){
		int l = 1, r = i;
		while (l <= r){
			int mid = (l + r) >> 1;
			if ((i - mid + 1) * a[i] - preS[i] + preS[mid - 1] > m) l = mid + 1;
			else r = mid - 1;
		}
		Ans = max(Ans, i - l + 1);
	}
	
	printf("%d\n", Ans);
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
