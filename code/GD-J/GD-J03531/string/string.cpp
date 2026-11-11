#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long ll;
int n;
ll a[N], ans;
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d" ,&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld" ,&a[i]);
		do c[i] = getchar();
		while(c[i] < 'a' || c[i] > 'z');
	}
	for(int i = 1, j = n;i < j;){
		int tmp = min(a[i], a[j]);
		if(c[i] != c[j]) ans += tmp;
		a[i] -= tmp; a[j] -= tmp;
		if(!a[i]) i++;
		if(!a[j]) j--;
	}
	printf("%lld" ,ans);
	return 0;
}
