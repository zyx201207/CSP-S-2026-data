#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n, m;
int a[N];
int num[N], v[N];
int ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	int j=1;
	num[1]=1, v[1]=0, ans=1;
	for(int i=2; i<=n; i++)
	{
		num[i]=num[i-1]+1;
		v[i]=num[i-1]*(a[i]-a[i-1])+v[i-1];
		while(v[i]>m)
		{
			v[i]-=(a[i]-a[j]);
			num[i]--;
			j++;
		}
		ans=max(ans, num[i]);
	}
	cout<<ans;
	return 0;
}
