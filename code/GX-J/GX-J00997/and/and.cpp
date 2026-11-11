#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
int n,m,ans;
int a[100010],f[200010];
bool cmp(int x,int y) {return x>y;}
int ok()
{
	int sum=a[f[1]];
	for(int i=2;i<=m;i++)
		sum &= a[f[i]];
	return sum;
}
void dfs(int k)
{
	if(k>m)
	{
		ans=max(ok(),ans);
		return;
	}
	if(n-f[k]<m-k) return;
	for(int i=f[k-1]+1;i<=n;i++)
	{
		f[k]=i;
		dfs(k+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	dfs(1);
	cout<<ans;
	return 0;
}
