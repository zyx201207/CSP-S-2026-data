#include<bits/stdc++.h>
using namespace std;
int n,m,ad[32][200005],cnt,is[200005];
long long a[200005],ans=INT_MAX;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int l=0;
		long long b=a[i];
		while(b)
		{
			l++;
			if(b%2==1) ad[l][++ad[l][0]]=i;
			b/=2;
		}
	}
	for(int i=31;i>=0;i--)
	{
		int sum=0;
		for(int j=1;j<=ad[i][0];j++) if(is[ad[i][j]]==cnt) sum++;
		if(sum>=m)
		{
			cnt++;
			for(int j=1;j<=ad[i][0];j++)
			{
				is[ad[i][j]]++;
			}
		}
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if(is[j]==cnt) sum++;
		}
		if(sum==m) break;
	}
	for(int i=1;i<=n;i++)
	{
		if(is[i]==cnt) ans&=a[i];
	}
	cout<<ans;
	return 0;
}
