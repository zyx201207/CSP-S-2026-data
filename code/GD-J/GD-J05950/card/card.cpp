#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005],f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++)
		{
			if(s[a[j]])
			{
				for(int k=s[a[j]];k<=j;k++)
				{
					s[a[k]]=0;
				}
			}
			s[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(s[j])
			{
				f[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}
