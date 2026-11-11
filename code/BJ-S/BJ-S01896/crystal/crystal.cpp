#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
using namespace std;
const int N=5e5+10;
long long a[N];
int cnt[N];
int main()
{
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		ll x=m;
		int j=i-1;
		while(x>0)
		{
			if(x<a[i]-a[j])
				break;
			cnt[i]++;
			x=x-a[i]+a[j];
			j--;
		}
	}
	int maxn=-1;
	for(int i=2;i<=n;i++)
		maxn=max(maxn,cnt[i]);
	cout<<maxn;
	return 0;
}
