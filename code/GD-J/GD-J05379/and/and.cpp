#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5*2+10;
int n,m;
ll a[N];
int s[N][35];
bool b[N];
int mxl;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=true;
		ll x=a[i];
		int l=0;
		while(x!=0)
		{
			s[i][++l]=x%2;
			x/=2;
		}
		mxl=max(mxl,l);
	}
	for(int i=mxl;i>=1;i--)
	{
		int t=0;
		for(int j=1;j<=n;j++)
		{
			if(s[j][i]&&b[j]) t++;
		}
		if(t>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(!s[j][i]) b[j]=false;
			}
		}
	}
	ll ans=1,m2=1;
	for(int i=1;i<=30;i++)
	{
		m2=m2<<1;
		ans+=m2;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]) ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
