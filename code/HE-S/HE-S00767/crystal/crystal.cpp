#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N];
long long cf[N];
long long hx;
int f[N];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cf[i]=a[i]-a[i-1];
	}
	hx=m;
	int cnt=0;
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(hx>=cf[i]*f[i-1])
		{
			f[i]+=f[i-1]+1;
			hx-=cf[i]*(f[i]-1);
		}
		else
		{
			while(hx<cf[i]*(f[i]+f[i-1]))
			{
				cnt++;
				hx+=a[i-1]-a[cnt];
				f[i]--;
			}
			f[i]+=f[i-1]+1;
			hx-=cf[i]*(f[i]-1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
