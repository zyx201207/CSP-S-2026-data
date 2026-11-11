#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int p[200005];
int maxn=-1;
int n,m;
void dfs(int nw,int k)
{
	if(k>m)
	{
		int sum=p[1];
		for(int i=2;i<=m;i++)
		{
			sum&=p[i];
		}
		maxn=max(sum,maxn);
		return;
	}
	if(nw>n) return;
	dfs(nw+1,k);
	p[k]=a[nw];
	dfs(nw+1,k+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,1);
	cout<<maxn;
	return 0;
}
