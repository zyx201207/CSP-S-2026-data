#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int b[n][5];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<5;j++)
		{
			b[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		while(a[i]>0)
		{
			int f=0;
			b[i][5-f-1]=a[i]%2;f++;
			a[i]/=2;
		}
	}
	long long c[n];
	for(int i=0;i<n;i++)
	{
		int s[5];
		for(int j=0;j<5;j++)
		{
			s[j]=1;
		}
		for(int j=0;j<5;j++)
		{
			for(int l=0;l<m;l++)
			{
				if(s[10-1-j] && b[(i+l)%n][5-i-j])
				{
					s[10-1-j]=1;
				}else{
					s[10-1-j]=0;
				}
			}
			if(s[10-1-j] >= 2)
			{
				s[10-2-j]+=s[10-1-j]/2;
				s[10-1-j]=s[10-1-j]%2;
			}
		}
		c[i]=s[0]*2*2*2*2+s[1]*2*2*2+s[2]*2*2+s[3]*2+s[4];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(c[j]<c[(j+1)%5])
			{
				int t=c[j];c[j]=c[(j+1)%5];c[(j+1)%5]=t;
			}
		}
	}
	cout<<c[0];
	return 0;
 } 
