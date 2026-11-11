#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c = getchar();
	int x = 0,neg = 1;
	while(c < '0' || c > '9'){
		if(c == '-') neg = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x*10 + c - '0';
		c = getchar();
	}
	return x * neg;
}
bool cmp(int a,int b){ return a > b; }
const int N = 5e5 + 10;
int n,ans = 0;
long long m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i = 1,j = 1;i <= n;i++){
		if(i > 1) m += (j-i+1) * (a[i-1] - a[i]);
		while(j < n && m >= a[i]-a[j+1]) m -= a[i]-a[j+1],j++;
		ans = max(ans,j-i+1);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7



*/
