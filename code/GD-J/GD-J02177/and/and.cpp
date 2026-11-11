#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],ans=-1;
bool v[N];
void dfs(int x,long long p)
{
	if(x==m)
	{
		ans=max(ans,p);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
		{
			v[i]=true;
			dfs(x+1,(p&a[i]));
			v[i]=false;
		}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n>2000&&m<=n) 
	{
		cout<<a[1];
		return 0;
	}
	dfs(0,pow(2,31)-1);
	cout<<ans;
	return 0;
}
