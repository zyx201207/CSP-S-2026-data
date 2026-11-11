#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll n,m,a[N],ans = -1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		ll l = i,r = i,sheng = m;
		while((l > 1 && a[l] - a[l - 1] <= sheng) || (r < n && a[r + 1] - a[r] <= sheng)){
			int df = -1;
			if(l > 1 && a[l] - a[l - 1] <= sheng){
				df = a[l] - a[l - 1];
				l--;
			}
			
			if(r < n && a[r + 1] - a[r] <= sheng){
				int dfr = a[r + 1] - a[r];
				if(df == -1) r++,df = dfr;
				else if(df > dfr) l++,r++,df = dfr;
			}
			sheng -= df;
		}
		ans = max(ans,r - l + 1);
	}
	cout << ans << a[1] << " " << a[n];
	return 0;
}
