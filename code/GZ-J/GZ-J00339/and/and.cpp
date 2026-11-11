//GZ-J00339 贵阳市南明区华麟学校 孙君瑞
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt=1,mmax=INT_MIN;
void dfs(int n,int xh,int s)
{
	if(cnt==m)
	{
		mmax=max(mmax,s);
		return;
	}
	for(int i=xh+1;i<=n;i++)
	{
		cnt++;
		dfs(n,i,a[i]&s);
		cnt--;
	}
	return;
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
	for(int i=1;i<n;i++)
	{
		dfs(n,i,a[i]);
	}
	cout<<mmax;
	return 0;
}
