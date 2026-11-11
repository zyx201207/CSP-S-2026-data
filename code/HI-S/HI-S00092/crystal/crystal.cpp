#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n;
long long m, a[N], d[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++) cin >> a[i];
    sort(a+1, a+n+1);
    long long ans = 0, sum = 0, x, c;
    for (int i = 1 ; i <= n ; i ++)
    {
    	x = abs(a[i]-a[i-1]);
    	sum += 1LL*d[i-1]*x;
    	if (sum > m)
    	{
    		c = ceil(1.0*(sum-m)/x);
    		d[i] = d[i-1]-c+1;
    		sum -= c*x;
		}
		else d[i] = d[i-1]+1;
		
	}
	for (int i = 1 ; i <= n ; i ++) ans = max(ans, d[i]);
	cout << ans;
	return 0;
}

