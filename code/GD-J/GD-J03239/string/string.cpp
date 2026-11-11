#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	scanf("%d", &n);
	int c[n];
	char ch[n];
	for (int i = 0;i<n;i++){
		scanf("%d %c", &c[i], &ch[i]);
	}
	int p = 0, q = n;
	long long ans = 0;
	while (p<q){
		if(c[p] > c[q]){
			c[p] -= c[q];
			if (ch[p] != ch[q]) ans += c[q];
			q--;
		}else if (c[p] == c[q]){
			p++;q--;
		}else if (c[p] < c[q]){
			c[q] -= c[p];
			if (ch[p] != ch[q]) ans += c[p];
			p++;
		}
	}
	printf("%lld", ans);
	return 0;
} 
