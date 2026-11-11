#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],e[500005],j11=1,ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[1]=1;
	e[1]=0;
	for(int i=2;i<=n;i++)
	{
		e[i]=e[i-1]+(a[i]-a[i-1])*f[i-1];
		f[i]=f[i-1]+1;
		while(e[i]>m)
		{
			e[i]-=a[i]-a[j11++];
			f[i]--;
		}
		ans=max(ans,f[i]);
	}
	cout<<ans;
}
