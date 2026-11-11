#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int a[N];
long long ans=-1e9;
int n,m;
void dfs(int x,int k,int sum)
{
	if(k==m+1)
	{
		if(sum>ans)
			ans=sum;
		return ;
	}
	for(int i=x+1;i<=n;i++)
		dfs(i,k+1,sum&a[i]); 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		dfs(i,2,a[i]);
	cout<<ans;
	return 0;
}
