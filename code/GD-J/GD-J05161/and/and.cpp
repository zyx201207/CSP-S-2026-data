#include<bits/stdc++.h>
using namespace std;
int n,m;
typedef long long ll;
long long a[200005];
long long ans=-1e9;
long long aaa(int x,int y)
{
	y--;
	for(int i=1;i<=n;i++)
		ans=max(ll(a[i] and x),ans);
	if(y!=0)
		ans=aaa(ans,y);
	return ans;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		cout<<ans<<endl;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					continue;
				else
					ans=max(ans,ll(a[i] and a[j]));
			}
		}
		cout<<ans<<endl;
		return 0;
	} 
	for(int i=1;i<=n;i++)
	{
		int z=a[i];
		a[i]=0;
		aaa(a[i],m);
		a[i]=z;
	}
	cout<<ans<<endl;
	return 0;
}
