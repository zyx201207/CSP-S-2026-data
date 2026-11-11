#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10,M=3e5+10;
ll a[N],ans[M],b[N],cnt=0,id;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		cnt=0;
		for(ll j=i;j<=n;j++)
		{
			bool flag=false;
			for(ll k=1;k<=cnt;k++)
			{
				if(b[k]==a[j])
				{
					flag=true;
					id=k;
					break;
				}
			}
			if(flag==false)
			{
				b[++cnt]=a[j];
			}
			else
			{
				cnt=id-1;
				b[++cnt]=a[j];
			}
		}
		for(ll j=1;j<=cnt;j++)
		{
			ans[b[j]]++;
//			cout<<b[j]<<" ";
		}
//		cout<<"\n";
	}
	for(ll i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
