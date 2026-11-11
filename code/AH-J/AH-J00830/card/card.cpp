#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005],t[100005],s[100005],p[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(!b[a[j]])
			{
				b[a[j]]=1;
				t[a[j]]=j;
			}
			else
			{
				for(int k=t[a[j]];k<j;k++)
				{
					p[k]=-1;
					b[a[k]]=0;
					t[a[k]]=0;
				}
				b[a[j]]=1;
				t[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(p[j]!=-1)
				s[a[j]]++;
		}
		memset(b,0,sizeof b);
		memset(t,0,sizeof t);
		memset(p,0,sizeof p);
	}
	for(int i=1;i<=m;i++)
		cout<<s[i]<<" ";
	return 0;
}
