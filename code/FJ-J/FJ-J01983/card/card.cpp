#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int n,m,a[2*M],ans[2*M],k[2*M];bool s[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int p=1;
		memset(k,0,sizeof(k));
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++)
		{
			if(s[a[j]]==0)
			{
				k[p++]=a[j];
				s[a[j]]=1;
			}
			else
			{
				for(int l=1;l<p;l++)
				{
					if(a[l]==a[j])
					{
						for(int w=l+1;w<p;w++)s[k[w]]=0,k[w]=0;
						p=l+1;
						break;
					}
				}
			}
		}
		for(int i=1;i<=m;i++)
			if(s[i])ans[i]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
