#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1000000;
ll n,m,ans=0;
ll a[N],cha[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
	{
		cha[i]=a[i]-a[i-1];
	}
	for(ll i=2;i<=n;i++)
	{
		ll sum=m,cnt=1,p=0;
		for(ll j=i;j>1;j--)
		{
			p+=cha[j];
			sum-=p;
			cnt++;
			if(sum<0)
			{
				cnt--;
				break;	
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
