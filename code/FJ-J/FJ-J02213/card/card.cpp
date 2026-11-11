#include<bits/stdc++.h>
using namespace std;
int p[1000000];
int s[1000000];
int a[1000000];
int c(int a,int b)
{
	for(int i=a;i<=b;i++)
	{
		if(s[i]==i)
			return s[i];
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s[j]=p[j];
			if(c(i,s[j]-1))
			{
				for(int k=c(i,s[j]-1);k<=s[j]-1;k++)
				{
					s[k]=0;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(s[k]==j)
				{
					a[j]++;
				}
			}
		}
	}
	a[1]--;
	for(int i=n;i>=1;i--)
	{
		if(a[i]==0)
		{
			continue;
		}
		cout<<a[i]<<' ';
	}
	return 0;
}
