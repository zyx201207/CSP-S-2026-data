#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
ll a[N];
bool cmp(ll u,ll v)
{
	return u<v;
}
ll sum[N]={0};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	int n;
	ll m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	int ans=1;
	int l=1,r=1;
	int ml,mr;
	ll ms,ma;
	sort(a+1,a+1+n,cmp);
	while(l<=r && r<=n)
	{
		r++;
		sum[r]=sum[r-1]+a[r];
		while(l<=r && a[r]*(r-l+1)-(sum[r]-sum[l-1]) > m)
		{
			l++;
		}
		/*
		if(ans < r-l+1)
		{
			ml=l;
			mr=r;
			ms=sum[r]-sum[l-1];
			ma=a[r];
			ans=r-l+1;
		}
		*/
		ans=max(ans,r-l+1);
	}
	//cout << ml << " " << mr << " " << ms << " " << ma << "\n";
	cout << ans << "\n";
	return 0;
}
/*
5 5 
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
