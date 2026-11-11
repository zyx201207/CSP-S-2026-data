#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, ans;
struct node{
	int num;
	char x;
}a[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i].num);
		cin >> a[i].x;
		if (a[i].x == a[i - 1].x){
			a[i - 1].num += a[i].num;
			i--, n--;
		}
	}
	for (int i = 1, j = n; i < j; ){
		int sum = min(a[i].num, a[j].num);
		if (a[i].x != a[j].x){
			a[i].x = a[j].x;
			ans += sum;
		}
		a[i].num -= sum;
		a[j].num -= sum;
		if (!a[i].num) i++;
		if (!a[j].num) j--;
	}
	printf("%lld", ans);
	return 0;
}
