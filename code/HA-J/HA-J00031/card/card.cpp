#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000001],b[10000001],s[100000001],d[10000001],f,s1,s2=1;
int main()
{
	ios::sync_with_stdio; 
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=j-1;k++)
			{
				if(b[k]==a[j]) b[k-1]=0;
			}
			b[j]=a[j];
		}
		f=1;
		for(int j=1;j<=n;j++)
		{
			if(f)
			{
				for(int k=1;k<=n;k++)
				{
					d[k]=s[b[k]]+1;
				}
			}
			s[b[j]]=d[j];
			s1++;
			if(b[j]=0) 
			{
				for(int k=1;k<=s1;k++)
				{
					s[k]--;
				}
			}
		}
		s2++;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=0) cout<<s[i]<<" ";
	}
	return 0; 
}
