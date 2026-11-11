#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=200005;
long long a[N];
long long dfs(int cnt,long long ans,int i)
{
	if(cnt==0)
	{
		return ans;
	}
	if(i==n)return 0;
	return max(dfs(cnt-1,ans&a[i],i+1),dfs(cnt,ans,i+1));
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	cout<<dfs(m,pow(2,30)-1,0);
	return 0;
}
