#include <bits/stdc++.h>           
#define maxn 100005
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	int a[maxn];
    int ans[maxn] = {};
	int game[100005], len;
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i++)
		scanf("%d", a+i);
	for(int i = 1;i <= n;i++){
		len = 0;
		for(int j = i;j <= n;j++){
			for(int k = 0;k < len;k++){
				if(a[j] == game[k]){
					len = k;
					break;
				}
			}
			game[len] = a[j], len++;
		}
		for(int k = 0;k < len;k++)
		{
			ans[game[k]] ++;
		}
	}
	for(int i = 1;i <= m;i++)
		printf("%d ", ans[i]);
	return 0;
}

