#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n, m;
LL a[500005];
LL sum;
int maxx = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int l = 1, r = 2; r <= n; r ++)
	{
		sum += (a[r] - a[r - 1]) * (r - l);
		while(sum > m)
			sum -= a[r] - a[l ++];
		maxx = max(maxx, r - l + 1);
	}
	cout << maxx;
	return 0;
}

