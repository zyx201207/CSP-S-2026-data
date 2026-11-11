#include<bits/stdc++.h>
using namespace std;
int n,a[100005],m,b[10005][10005],c=1,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=n;i>=n-m+1;i--)
	{
		int k=a[i];
		c=1;
		while(k==0)
		{
			
			b[a[i]][c]=k%2;
			k/=2;
		    c++;
		}
	}
	for(int i=n;i>n-m;i--)
	{
		for(int j=1;;j++)
		{
			if(b[a[i]][j]==b[a[i-1]][j] &&b[a[i]][j]==1)
			{
				sum++;
			}
			if(b[a[i]][j]==0&&b[a[i-1]][j]==0)
			break;
		}
	}
	bool flag=false;
	for(int i=n;i>n-m;i--)
	{
		if(a[i]%2==0)flag=true;
	}
	if(flag==true)
	{
		int s=2;
		for(int i=2;i<=sum;i++)
		{
			s=s+s*2;
		}
		cout<<s;
	}
	else{
			int s=2;
		for(int i=2;i<=sum;i++)
		{
			s=s+s*2;
		}
		cout<<s+1;
	}
	return 0;
} 
