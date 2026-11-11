#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
long long n,m;
long long ans;
long long x;
void dfs(long long i,long long x)
{
	if(i>n)return;
	if(x>m)
	{
		
	    for(int i=1;i<=n;i++)
	    {
		    long long sum=0;
	    	for(int j=1;j<=n;j++)
	    	{
	    		if(a[i]==a[j])sum++;
			}
			ans=max(ans,sum);
		}
		
		return;
	} 
	
	a[i]+=1;
	dfs(i,x+1);
	dfs(i+1,x+1);
	a[i]-=1;
	dfs(i+1,x);
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>1000)
	{
		x=a[2]-a[1];
		int y=x;
		ans++;
		while(m-y>=0)
		{
			ans++;
			m-=y;
			y+=x;
		}
	}
	else dfs(1,1);
	cout<<ans;
 	return 0;
} 
