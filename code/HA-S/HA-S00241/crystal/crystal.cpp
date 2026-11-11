#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N=5e5+5;
int a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	bool flag1=true,flag2=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0,sum=0;
	sort(a,a+n);
	for(int i=2;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int t=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n&&j!=i;j++)
		{
			int len=abs(a[j]-a[i]);
			if(sum+len>m)
			{
				break;
			}
			sum+=len;
			t++;
		}
		ans=max(ans,t);
		sum=0;t=0;
	}
	cout<<ans+1;
	return 0;
}
