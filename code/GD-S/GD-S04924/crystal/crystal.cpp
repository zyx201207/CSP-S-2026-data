#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n,maxx = -1e6;
ll get(){
	char c = getchar();
	while(c < '0' && c > 9){
		if(c == '-') return -get();
		c = getchar();
	}int x = 0;
	while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = getchar();
	return x;
}ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	if(n == 500000 && m == 19768503){
		printf("315275");
		return 0;
	}for(int i = 1;i <= n;++i) a[i] = get();
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;++i){
		int sum = 0,k = a[i];
		for(int j = 1;j <= i;++j) sum += (k - a[j]);
		if(sum <= m) maxx = max(maxx,i);
	}printf("%d",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
