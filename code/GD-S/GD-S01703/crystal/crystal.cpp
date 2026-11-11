#include<bits/stdc++.h>
using namespace std;
int n;
long long m, a[500001];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	int ans = 1;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		int pos;
		long long mm = m;
		for(int j = i - 1; j; j--)
			if(mm >= a[i] - a[j]){
				mm -= (a[i] - a[j]);
				pos = j;
			}
		ans = max(ans, i - pos + 1); 
	}
	printf("%d\n", ans);
} 
