#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, s, i, j;
struct node{
	int x;
	char c;
}a[200005];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for(i=1; i<=n; i++) scanf("%lld %c", &a[i].x, &a[i].c);
	i=1, j=n;
	while(i<j){
		int h=min(a[i].x, a[j].x);
		if(a[i].c!=a[j].c) s+=h;
		a[i].x-=h, a[j].x-=h;
		if(!a[i].x) i++;
		if(!a[j].x) j--;
	}
	printf("%lld", s);
	return 0;
} 
