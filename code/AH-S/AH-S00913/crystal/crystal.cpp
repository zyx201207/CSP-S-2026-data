#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=5e5+5;
ll a[Maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll sum=0;
	int L=1;
	int ans=0;
	for(int R=1;R<=n;R++)
	{
		sum+=a[R];
		while(a[R]*1LL*(R-L+1)-sum>m)
		{
			sum-=a[L];
			L++;
		}
		ans=max(ans,R-L+1);
	}
	cout << ans;
	return 0;
}