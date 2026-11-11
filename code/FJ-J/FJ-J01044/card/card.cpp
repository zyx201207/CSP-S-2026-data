//card
#include<bits/stdc++.h>
using namespace std;
int a[300005];
int t[300005];
int sum[300005];
int ans[300005];
bool p[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(p,0,sizeof(p));
		memset(t,0,sizeof(t));
		memset(sum,0,sizeof(sum));
		for(int j=i;j<=n;j++)
		{
			if(p[a[j]]==1)
			{
				int st;
				for(int k=1;k<=cnt;k++)
				{
					if(t[k]==a[j])
					{
						st=k;
						break;
					}
				}
				for(int k=st;k<=cnt;k++)
				{
					sum[t[k]]--;
					if(sum[t[k]]==0)
					p[t[k]]=0;
					t[k]=0;
				}
				sum[a[j]]++;
				p[a[j]]=1;
				t[st]=a[j];
				cnt=st;
			}
			else
			{
				sum[a[j]]++;
				p[a[j]]=1;
				t[++cnt]=a[j];
			}
		}
		for(int j=1;j<=m;j++)
		if(p[j]==1)
		ans[j]++;
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}
