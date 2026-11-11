#include<bits/stdc++.h>
using namespace std;
int n,m; 
int p[200005],maxn=-1;
int f(int a,int b)
{
	int t=1,c=0;
	if(a==b)return a;
	while(a>0 and b>0)
	{
		if(a%2==1 and b%2==1)c+=t;
		t*=2,a/=2,b/=2;
	}
	return c;
}
void dfs(int a,int k,int t)
{
	if(t==m)maxn=max(a,maxn);
	if(a<maxn)return ;
	if(k==n+1)return ;
	dfs(f(a,p[k]),k+1,t+1);
	dfs(a,k+1,t);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>p[i];
    dfs(1073741823,1,0);
    cout<<maxn;
    return 0;
}
