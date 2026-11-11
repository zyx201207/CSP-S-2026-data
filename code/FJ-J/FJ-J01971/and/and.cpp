#include<bits/stdc++.h>
using namespace std;
int a[20005]={0};
int n,m;
//yu:Now the number of &'s number which was chosen;
//s:the number which has been chosen;
//k:pos
int dfs(int yu,int s,int k)
{
	if(k+(m-s)>n)return 0;
	if(s==m)return yu;
	int maxn=-1;
	for(int i=k+1;i<=n;i++)
	{
		maxn=max(maxn,yu&dfs(yu&a[i],s+1,i));
//		cout<<"yu="<<yu<<" a[i]="<<a[i]<<" s="<<s<<" i="<<i<<" maxn="<<maxn<<" f="<<(yu&dfs(yu&a[i],s+1,i))<<endl;
	}
	return maxn;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		int ans=-1;
		for(int i=1;i<=n;i++)if(a[i]>ans)ans=a[i];
		cout<<ans;
		return 0;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		int maxn=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((a[i]&a[j])>maxn)
				{
					maxn=a[i]&a[j];
//					cout<<"i="<<i<<"j="<<j<<endl; 
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	else
	{
//		cout<<"hello";
		int ans=-1;
		for(int i=1;i<n-m+1;i++)
		{ 
//			cout<<"i="<<i<<" function="<<dfs(a[i],1,1)<<endl;
			ans=max(ans,dfs(a[i],1,1)); 
		}
		cout<<ans;
	}
	return 0;
}
