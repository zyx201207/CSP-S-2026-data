#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
bool flag[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt=n;
	for(int i=(1ll<<32);i>=1;i/=2)
	{
		int c=0ll;
		for(int j=1;j<=n;j++)
		{
			if(flag[j])continue;
			if((a[j]/i)%2ll==0ll)c++;
		}
		if(cnt-c>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(flag[j])continue;
				if((a[j]/i)%2ll==0ll)flag[j]=1;
			}
			cnt-=c;
		}
	}
	int t=-1;
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==0&&t==-1)t=a[i];
		else if(flag[i]==0)t&=a[i];
	}
	cout<<t;
	return 0;
}
