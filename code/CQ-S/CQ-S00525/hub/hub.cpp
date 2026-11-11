#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e8+5;
ll a[maxn];
ll n,m;
ll op,po; // op=OPerate, po=POsition
ll pov; // POsition Value
ll ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;po=n;)
	{
		if(i=1)
		{
			po=1;
		}
		else
		{
			pov=a[i];
			if (a[i]<pov)
			{
				a[i]=a[i]+1;
				pov=a[i];
				continue;
			}
			if (a[i]=pov)
			{
				i++;
				continue;
			}
			else
			{
				return 0;
			}
			continue;
		}
		
	}
	cout<<po;
	
	
	
	
	
	
//	for(int i=1;po=n;)
//	{
//		if(i=1)
//		{
//			po = 1;
//		}
//		else
//		{
//			if(a[i]<a[i+1])
//			{
//				a[i]=a[i]+1;
//				op++;
//				continue; 
//			}
//			if(a[i]==a[i+1])
//			{
//				po++; 
//				i++;
//				break;
//			}
//			else
//			{
//
//			}
//		}
//	}
//	for(int i=1;i<=n;)
//	{
//		if(a[i]==a[i+1])
//		{
//			ans++;
//			i++;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	cout<<ans;
}
