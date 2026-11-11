#include <bits/stdc++.h>
typedef long long ll; 
using namespace std;

ll a[500010],n,m,ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a + n);
	int need = 0,l = 0,mx = 0;
	for(int r = 0;r < n;r++)
	{
		while(need > m)
		{
			need -= a[r] - a[l];
			l++;
		}
		mx = max(mx,r - l + 1);
		need += (a[r + 1] - a[r]) * (r - l + 1);
	}
	cout << mx;
	return 0;
}
