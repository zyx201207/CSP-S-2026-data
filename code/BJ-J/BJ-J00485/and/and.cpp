#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	string s;
}a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		maxx=max(maxx,a[i].x);
	}
	if(k==1)
	{
		cout<<maxx;
		return 0;
	}
	if(k==n)
	{
		int ans=0;
		for(int j=0;j<=20;j++)
		{
			int p=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].x%2==0) p=1;
				a[i].x/=2;
			}
			if(p==0)
			{
				ans+=pow(2,j);
			}
		}
		cout<<ans;
	}
	if(k==2)
	{
		int ans=0;
		for(int i=1;i<n;i++)
		{
			for(int m=i+1;m<=n;m++)
			{
				int c=a[i].x,d=a[m].x;
				int ccnt=0;
				for(int j=0;j<=20;j++)
				{
					if(c%2==1 && d%2==1) ccnt+=pow(2,j);
					c/=2;
					d/=2;
				}
				ans=max(ans,ccnt);
			}
		}
		cout<<ans;
	}
	return 0;
}
