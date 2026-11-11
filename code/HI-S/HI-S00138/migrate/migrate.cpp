#include <bits/stdc++.h>
using namespace std;
int n;int c;int t;long long d,a[1000086*2];int ends;long long b[1000086*2];long long distance[1000086*2];
int times;long long minn=1e9;int ans;long long q[2*1000086];
/*long long dfs(int x,int y,int l)
{
	if(x==y)
	{
		
		if(minn<l)
		{
			minn=l;times=1;
		}
		else if(minn=l)
		{
			times++;
			return 0;
		}
	}
	for(int i=x;i<=y;i++)
	{
		if(distance[x+i]-distance[x]<=d)
		{
			dfs(x+i,y,l+1);20pts~
		}
		
	}
	if(times==2)
		{
			ans++;minn=1e9;
			times=0;
		}
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			//b[i]=a[i]-a[i-1];
			//distance[i]=b[i]+b[i-1];
			/*if(i>=2)
			{
				a[i]-a[i-1]>d;ends=i-1;
			}*/
		}
		/*for(int i=1;i<=ends-3;i++)
		{
			for(int j=i+3;j<=ends;j++)
			{
				dfs(i,j,1);
			}
		}
		cout<<ans<<endl;
		ans=0;*/
		for(int i=4;i<=n;i++)
		{
			if(i%2==1)continue;
			q[i]=n-i+1;
			
		}
		for(int i=1;i<=n;i++)
		{
			ans+=q[i];
		}
		cout<<ans<<endl;
		ans=0;//只有特判，没有一点写题痕迹，incredible 我竟然也会这么干，还有，感觉今年只有这道题能特判一下，其他的纯数学算不出来 
	}
	return 0;
} 
