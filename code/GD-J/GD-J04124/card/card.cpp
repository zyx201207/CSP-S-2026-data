#include<bits/stdc++.h>
using namespace std;
long long a[500005],q[500005],ans[500005],s[300005],t[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//  freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//  freopen("ans.in","r",stdin);
//	freopen("ans.out","w",stdout);
	long long n,m;
	bool A=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) A=false;
	}
	if(A)
	{
		for(int i=1;i<=n;i++)
		{
			int k=0;
			for(int j=i;j<=m;j++)
			{
				if(a[j]>1)
				{
					memset(q,0,sizeof(q));
					k=1;
					q[k]=a[j];
				}
				else
				{
					q[++k]=a[j];
				}
			}
			for(int j=1;j<=k;j++)
			{
				ans[q[j]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	else if(n<=500&&m<=200)
	{
		for(int i=1;i<=n;i++)
		{
			memset(s,0,sizeof(s));
			memset(q,0,sizeof(q));
			long long y=0;
			for(int j=i;j<=n;j++)
			{
				if(s[a[j]]!=0)
				{
					for(int k=s[a[j]]+1;k<=y;k++)
					{
						s[k]=0;
					}
					y=s[a[j]];
				}
				else
				{
					y++;
					q[y]=a[j];
					s[a[j]]=y;
				}
			}
			for(int j=1;j<=y;j++)
			{
				ans[q[j]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<"1 ";
	}
	return 0;
}
