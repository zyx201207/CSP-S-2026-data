#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, m;
int a[N];
int b[40], c[N], s1[N][40], s[N][40];

int main(){
	freopen("and.in","r", stdin);
	freopen("and.out","w", stdout); 
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort(a + 1; a + n + 1);
	printf("%d", a[n - m + 1]);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
