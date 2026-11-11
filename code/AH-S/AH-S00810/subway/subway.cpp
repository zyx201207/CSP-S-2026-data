#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int f[N],sum;
void dfs(int u,int v)
{
	for(int i=1;i<=n;i++)
		if(u<=i&&v>i)
			return true;
	return false;		 
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>n>>m;
	int a;
	for(int i=1;i<=n;i++)
	{
		while(cin>>a)
			dfs(1);
		sum++;
	}
	cout<<sum;
	return 0;	
}
