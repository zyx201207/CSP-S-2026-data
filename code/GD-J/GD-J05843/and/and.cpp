#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200007];
long long dfs(long long x,long long s,long long sum)  //x 位置   s 数量   sum 和 
{
	if(s>=m) return sum;
	if(x>n&&s<m) return 0;
	if(sum==0)
	{
		return max(dfs(x+1,s+1,a[x]),dfs(x+1,s,0));
	}
	return max(dfs(x+1,s+1,(sum&a[x])),dfs(x+1,s,sum));

}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=dfs(1,0,0);
	cout<<ans;
	return 0;
}
