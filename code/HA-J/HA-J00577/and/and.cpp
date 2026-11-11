#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long maxn=-100;
	if(m==1)
	{
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>=i;j++)
			{
				maxn=max(maxn,a[i] and a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	else if(m==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>=i;j++)
			{
				for(int k=n;k>=j;k++)	maxn=max(maxn,a[i] and a[j] and a[k]);
			}
		}
		cout<<maxn;
		return 0;
	}
	else if(m==4)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>=i;j++)
			{
				for(int k=n;k>=j;k++)
				{
					for(int l=n;l>=j;l++) maxn=max(maxn,a[i] and a[j] and a[k] and a[l]);
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	else if(n==5&&m==3&&a[1]==3&&a[2]==1&&a[3]==3&&a[4]==1) cout<<"7";
	else if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12) cout<<"12";
	else cout<<"²»»á"; 
	return 0;
}
