#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[6001000];
//bool used[100001100];
long long ans=-1e18;
long long path[6001000];
void dfs (long long now,long long min)
{
	if(now==m+1)
	{
		//cout<<"拿完了"<<endl;
		for(int i=2;i<now;i++)
		{
			path[i]=path[i-1]&path[i];
		}
		
		ans=max(ans,path[now-1]);
		//cout<<"总结果为"<<path[now-1]<<"最大结果为"<<ans<<endl;
		//cout<<"retrun"<<endl;
		return ;
	}
	for(long long i=min+1;i<=n;i++)
	{
		//cout<<"选择:"<<a[i]<<endl;
		path[now]=a[i];
		dfs(now+1,i);
	}
	//cout<<"return"<<endl;
	return ;
}
signed main()
{
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	
	
	
	
	return 0;
 } 
