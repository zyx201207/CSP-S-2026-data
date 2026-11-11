#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long a[1000005];
int ans,k;
int find(int x)
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]==x) return mid;
		if(a[mid]<x&&a[mid+1]>x) return mid;
		if(a[mid]>x) r=mid;
		if(a[mid]<x) l=mid; 
	}
}
int su;
void dfs(int id,int y,int s)
{ 
	if(s>k) return;
	if(id==y) 
	{
		if(s==k) su++;
		return;
	}
	if(id>y) return;
	for(int i=id+1;i<=n;i++)
	{
		if(a[i]-a[id]<=d) dfs(i,y,s+1);
	} 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				k=1;
				int qi=i;
				while(1)
				{
					if(a[qi]+d>=a[j]) break;
					if(a[qi]+d<a[qi+1])
					{
						k=-1;
						break;
					}
					qi=find(a[qi]+d);
					k++;
				}
				if(k==-1) continue;
				k++;
				su=0;
				dfs(i,j,1);
				if(su==2) ans++;
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
}
