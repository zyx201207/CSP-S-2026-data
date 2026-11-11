#include<bits/stdc++.h>
using namespace std;

int n, m, a[500001];

int main(){
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++){
		int ans = 0, num;
		for (int j = 1; j <= n; j++){
			num = 0;
			for (int l = j; l <= n; l++)
				if (a[l] == i)
					num++;
			if (num % 2)
				ans++;
		}
		printf("%d ", ans);
	}
	
	return 0;
}

