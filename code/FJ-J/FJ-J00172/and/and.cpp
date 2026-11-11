#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200078];
int ma=-99999;
void dfs(int x,int xz,int c)
{
	if(xz<=ma)return;
	if(!c){ma=max(ma,xz);return;}
	for(int i=x+1;i<n;i++)
	{
		dfs(i,xz&a[i],c-1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>ma)dfs(i,a[i],m-1);
	}
	cout<<ma;
}
