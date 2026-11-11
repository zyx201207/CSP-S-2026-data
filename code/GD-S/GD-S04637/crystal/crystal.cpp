#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
void solve()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n+1);
	vector<__int128> presum(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.begin()+1+n);
	a[0]=a[1];
	presum[0]=0;
	for(int i=1;i<=n;i++)		
		presum[i]=presum[i-1]+(a[i]-a[i-1])*(i-1);//把i前所有数变成a_i的代价 
	a[0]=0;
	ll ans=0,l=1,r=1;
	while(l<=n&&r<=n)
	{
		if((presum[r]-presum[l]-(a[r]-a[l])*(l-1)<=m||l==r)&&r<n)ans=max(ans,r-l+1),r++;
		else l++;
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll T=1;//cin>>T;
	while(T--)solve();
	return 0;
}

