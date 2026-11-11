#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;

int n, m;
int a[N];
bool isHave[M];
int Ans[M];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for (int l = 1; l <= n; l++){
		for (int i = l; i <= n; i++){
			if (isHave[a[i]])
				for (int j = i - 1; a[j] != a[i]; isHave[a[j]] = 0, j--);
			isHave[a[i]] = 1;
		}
		for (int i = 1; i <= m; i++)
			if (isHave[i]) Ans[i]++, isHave[i] = 0;
	}
	
	for (int i = 1; i <= m; i++) printf("%d ", Ans[i]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
