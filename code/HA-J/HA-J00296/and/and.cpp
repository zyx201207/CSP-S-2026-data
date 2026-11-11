#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(int x,int y)
{
	return(x>y);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==m)
	{
		cin>>a[1];
		long long ans=a[1];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(m==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int b;
			cin>>b;
			ans=max(ans,b);
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1,cmp);
		int ans=a[1];
		for(int i=2;i<m;i--)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}

}
