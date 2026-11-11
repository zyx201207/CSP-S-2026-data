#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+10;
long long a[N],b=0,c,d,n,m,max1;
char x,y;
void dfs(long long x,long long k,long long sum)
{
	if(k==m) 
	{
		max1=max(sum,max1);
		return ;
	}
	for(int i=x;i<=n;i++)
	{
		dfs(i+1,k+1,sum&a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n; 
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i+1,1,a[i]);
	}
	cout<<max1;
	return 0;
 } 
