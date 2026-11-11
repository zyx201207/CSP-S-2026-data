#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]<=a[i])
			{
				b[++cnt]=a[i]-a[j];
			}
			else
			{
				break;
			}
		}
		sort(b+1,b+cnt+1);
		int s=0,x=0;
		for(int j=1;j<=cnt;j++)
		{
			if(s+b[j]<=m)
			{
				s+=b[j];
				x++;
			}
			else
			{
				break;
			}
		}
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}
