#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
void mj(int k,int t,int s)
{
	if(k==0)
	{
		ans=max(ans,s);
	}
	for(int i=t+1;i<=n;i++)
	{
		mj(k-1,i,s&a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++)
	{
		mj(m-1,i,a[i]);
	}
	cout<<ans;
	return 0;
}
