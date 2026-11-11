# include <bits/stdc++.h>
# define N 510050
using namespace std;
long long n , m , a[N] , sum[N] , p[N]  , ans;
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin >>n >> m;
    for(int i = 1; i <= n; i ++)
     cin >> a[i];
    
    sort(1 + a , 1 + a + n);//-3 -1 1 6 7
    long long l = 1;
    ans = 1;
    long long ln = 0;
    for(int r = 2; r <= n; r ++)
    {
    	ln += (a[r] - a[r-1]) * (r-l);
    	while(ln > m && l < r)
    	{
//    		if(ln + (a[r] - a[r-1]) * (r-l) == m) ans = max(ans , (r-l+1));
            ln -= a[r] - a[l] , l ++;
		}
	
//		cout << l << " " << r << " " << ln + (a[r] - a[r-1]) *(r-l)<<'\n';
    	if(ln <= m)ans = max((r-l+1) , ans);
	}
    cout << ans;
}