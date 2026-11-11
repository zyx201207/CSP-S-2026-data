#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,s,s1,a[500005],b[300005],l[500005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++) c[j]=a[j];
		memset(l,0,sizeof l);
		for(j=i;j<=n;j++)
		{
			if(l[c[j]])
			{
				for(int k=l[c[j]];k<j;k++)
				{
					//cout<<k<<' ';
					l[a[k]]=0;
					c[k]=-1;
				}
				
			}
			l[c[j]]=j;
		}
		for(j=i;j<=n;j++)
		{
			if(c[j]!=-1) 
			{
				b[c[j]]++;
				//cout<<c[j]<<' ';
			}
		}
		//cout<<'\n';
	}
	for(i=1;i<=m;i++) cout<<b[i]<<' ';
}
