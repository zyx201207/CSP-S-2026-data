#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],sum[45][200005],k;
string s[200005],model="01";
string ten_to_r(ll n,ll k)
{
	string ans;
	while(n)
	{
		ans+=model[n%2];
		n/=2;
	}
	reverse(ans.begin(),ans.end());
	while(ans.size()<35)ans='0'+ans;
	return ans;
}	
bool cmp(const string &x,const string &y)
{
	return x>y;
}
ll quick(ll a,ll b)
{
	ll res=1;
	for(ll i=1;i<=b;i++)res*=a;
	return res;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)s[i]=ten_to_r(a[i],2);
	ll ans2=0;
	k=n;
	for(ll i=0;i<=34;i++)
	{
		ll cnt=0;
		for(ll j=1;j<=k;j++)
		{
			if(s[j][i]=='1')cnt++;
		}
		if(cnt<m)
		{
			for(ll j=1;j<=k;j++)s[j][i]='0';
		}
		else
		{
			sort(s+1,s+k+1,cmp);
			ans2+=quick(2,34-i);
			ll f=k;
			for(ll j=1;j<=k;j++)
			{
				if(s[j][i]=='0')
				{
					f=j-1;
					break;
				}
			}
			k=f;
			for(ll j=1;j<=k;j++)s[j][i]='0';
		}
	}
	cout<<ans2;
	return 0;
}
