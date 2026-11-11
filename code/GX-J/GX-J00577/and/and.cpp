#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int n,m,a[200001],ans,mx;
int main()
{
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			mx=max(mx,a[i]);
		}
		if(m==1)
		{
				cout<<mx;
				return 0;
		}
		if(m==n)
		{
			int p=a[1];
			for(int i=2;i<=n;i++)
				p=p&a[i];
			cout<<p;
			return 0;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
					int x=a[i]&a[j];
					ans=max(ans,x);
			}
		cout<<ans;
		return 0;
}
	

