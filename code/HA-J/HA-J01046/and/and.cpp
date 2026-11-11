#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],ans=-1e9;
long long dfs(long long deep,long long sum)
{
    if(deep==m+1)
	{
		ans=max(ans,sum);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			dfs(deep+1,sum&a[i]);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long t=a[i];
				t=t&a[j];
				ans=max(ans,t);
			}
		}
	}
	else{
	    dfs(1,pow(2,31)-1);
	}
		
		
	cout<<ans;
	return 0;
} 
