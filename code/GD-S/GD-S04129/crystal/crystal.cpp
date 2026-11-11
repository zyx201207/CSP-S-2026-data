#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
int n;
i64 m;
i64 a[500007];
i64 s[500007];
i64 w(int l,int r)
{
	return a[r] * (r - l + 1) - s[r] + s[l-1];
}
int ans = 0;
signed main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i] = s[i-1] + a[i];
	for(int i=1,j=1;i<=n;i++)
	{
		while(w(j,i)>m)
			j++;
		ans = max(ans,i-j+1);
	}
	cout<<ans<<'\n';
}

