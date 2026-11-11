#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10;
int n, m, a[N], d[N], b[N], s[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	for(int i = 1; i <= n; i++){
		memset(b, 0, sizeof(b));
		memset(s, 0, sizeof(s));
		for(int j = i; j <= n; j++){
			int x = a[j];
			int l = INT_MAX;
			
			for(int k = i; k < j && l == INT_MAX; k++)
				if(a[k] == x && s[k] != -1) l = k;
			for(int k = l; k < j; k++)
				s[k] = -1;
		}
		for(int j = i; j <= n; j++)
			if(s[j] == 0) d[a[j]]++;
//		for(int j = i; j <= n; j++) printf("%d ", s[j]);
//		printf("\n");
	}
	for(int i = 1; i <= m; i++)
		printf("%d ", d[i]);
}
