#include<bits/stdc++.h>
using namespace std;
int n,m,a[1110000],s[1110000],ans[1110000];
bool r[1110000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=m;j++)
		{
			r[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(r[a[j]]==1)
			{
				while(s[cnt]!=a[j])
				{
					r[s[cnt]]=0;
					s[cnt--]=0;
				}
			}
			else
			{
				s[++cnt]=a[j];
				r[a[j]]=1;
			}
		}
		for(int j=1;j<=cnt;j++)
		{
			ans[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i==m)
		{
			cout<<ans[i];
		}
		else cout<<ans[i]<<" ";
	}
	return 0;
}
