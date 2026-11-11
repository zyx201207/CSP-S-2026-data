#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct node
{
	ll ai;
	char ci;
}a[N];
int n;
ll ans,l,r,lnow,rnow,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].ai>>a[i].ci;
		sum+=a[i].ai;
	}
	l=1,r=sum,lnow=1,rnow=n;
	while(l<r)
	{
		if(a[lnow].ci!=a[rnow].ci)
		{
			if(a[lnow].ai>a[rnow].ai)
			{
				r-=a[rnow].ai;
				l+=a[rnow].ai;
				ans+=a[rnow].ai;
				a[lnow].ai-=a[rnow].ai;
				rnow--;
			}
			else if(a[lnow].ai<a[rnow].ai)
			{
				r-=a[lnow].ai;
				l+=a[lnow].ai;
				ans+=a[lnow].ai;
				a[rnow].ai-=a[lnow].ai;
				lnow++;
			}
			else
			{
				r-=a[lnow].ai;
				l+=a[lnow].ai;
				ans+=a[lnow].ai;
				lnow++;
				rnow--;
			}
		}
		else
		{
			if(a[lnow].ai>a[rnow].ai)
			{
				a[lnow].ai-=a[rnow].ai;
				r-=a[rnow].ai;
				l+=a[rnow].ai;
				rnow--;
			}
			else if(a[lnow].ai<a[rnow].ai)
			{
				a[rnow].ai-=a[lnow].ai;
				r-=a[lnow].ai;
				l+=a[lnow].ai;
				lnow++;
			}
			else
			{
				r-=a[lnow].ai;
				l+=a[lnow].ai;
				rnow++;
				lnow--;
			}
		}
	}
	cout<<ans;
	return 0;
}
