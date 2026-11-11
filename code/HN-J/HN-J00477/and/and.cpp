#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
using namespace std;
int a[10007];
bool vis[10007];
bool viss[10007];
long long maxx=0;
long long maxxx=0;
int n,m;
void print()
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		    cout<<a[i]<<" ";
	}
	cout<<endl;
}
void dfs(int level)
{
	if(level==m+1)
	{
		maxx=max(maxx,maxxx);
	    return ;
	}
	for(int i=level;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			if(level==1)
			    maxxx=a[i];
			else
			    maxxx &= a[i];
			dfs(level+1);
		    maxxx=a[i];
		    vis[i]=false; 
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1);
    cout<<maxx;
}
