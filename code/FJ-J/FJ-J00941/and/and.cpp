#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, m;
int a[N];
int cnt[31];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	
	int high_pos = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		
		int tp = a[i], pos = 1;
		while (tp != 0){
			bool w = tp & 1;
			if (w) cnt[pos]++;
			tp >>= 1, pos++;
		}
	}
	
	for (int i = 1; i <= 30; i++)
		if (cnt[i] >= m) high_pos = i;
	
	int Mod = pow(2, high_pos);
	for (int i = 1; i <= n; i++){
		a[i] %= Mod;
	}
	sort(a + 1, a + 1 + n, cmp);
	
	int Ans = a[1];
	for (int i = 2; i <= m; i++) Ans &= a[i];
	
	printf("%d\n", Ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
