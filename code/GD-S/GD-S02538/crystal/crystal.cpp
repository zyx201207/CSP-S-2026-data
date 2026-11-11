#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>0;--i)
	{
		a[i]-=a[i-1];
	}
	ll ans=0,cnt=1,sum=0,ad=0;
	ll cntad=0;
	for(int i=1;i<n;++i)
	{
		ad+=a[i];
		sum+=a[i]*(i-cntad);
		++cnt;
		while(sum>m)
		{
			++cntad;
			--cnt;
			sum-=ad;
			ad-=a[cntad];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
