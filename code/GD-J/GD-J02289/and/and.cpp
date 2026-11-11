#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int main()
{
	freopen("and3.in","r",stdin);	
	freopen("and3.out","w",stdout);	
	ll a,b,c[N],d[N],maxn=-9999;
	cin>>a>>b;	
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	if(b==1&&a>20)
	{
		for(int i=1;i<=a;i++)
		{
			if(maxn<c[i])
				maxn=c[i];
		}
		cout<<maxn;
		return 0;
	}
	if(b==a&&a>20)
	{
		ll ha=c[1];
		for(int i=2;i<=a;i++)
		{
			ha=ha&c[i];
		}
		cout<<ha;
		return 0;
	}
	if(b==2&&a>20)
	{
		int maxo=-9999,fg=0;
		for(int i=1;i<=a;i++)
		{
			if(maxn<c[i])
			{
				maxn=c[i];
				fg=i;
			}
		}
		for(int i=1;i<=a;i++)
		{
			if(maxo<c[i]&&i!=fg)
				maxo=c[i];
			
		}
		long long rrrr=maxn&maxo;
		cout<<maxo;
		return 0;
	}
	sort(c+1,c+a+1);
	ll m=c[a];
	for(int i=a-1;i>=a-b+1;i--)
	{
		m=m&c[i];
	}
	cout<<m;
	
 } 
