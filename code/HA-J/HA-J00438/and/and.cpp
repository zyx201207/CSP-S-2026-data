#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,Max=-1;
int a[N];
void dfs(int i,int x,int num)
{
	if(i==n+1) return;
	if(x==m)
	{
		Max=max(Max,num);
		return;
	}
	if(x==0) dfs(i+1,x+1,a[i+1]);
	dfs(i+1,x+1,(num&a[i+1]));
	dfs(i+1,x,num);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int c=0,t=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==pow(2,i)) c++;
		if(a[i]==i-1) t++;
	}
	if(n>2000&&c==n)
	{
		cout<<a[n-m+1];
		return 0;
	}
	dfs(0,0,0);
	cout<<Max;
	return 0;
}

