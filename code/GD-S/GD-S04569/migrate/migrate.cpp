#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[5000010],dp[5000010],g[5000010],e,ans,mn;
bool f;
void dfs(int x,int step)
{
	if(step>mn)	return ;
//	cout<<x<<" "<<step<<endl;
	if(x==e)
	{
//		cout<<x<<"#"<<step<<"#"<<mn<<endl;
		if(step==mn)
			ans++;
		if(step<mn)
		{
			mn=step;
//			cout<<step<<"**"<<mn<<endl;
			ans=1;
		}
		return ;		
	}
	for(int i=x+1;i<=e;i++)
	{
//		cout<<mn<<endl;
		if(d>=a[i]-a[x])
		{
			dfs(i,step+1);
//			cout<<x<<"#"<<i<<" "<<a[x]<<" "<<a[i]<<endl;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int s=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i!=1)
			a[i]=a[i]-a[1];
		}
//		cout<<a[4]<<endl;
		a[1]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				f=false;
				mn=0x3f3f3f3f;
				ans=0;
				e=j;
				dfs(i,0);
//				cout<<i<<" "<<j<<" "<<ans<<endl;
				if(ans==2)
				{
//					cout<<i<<" "<<j<<endl;
					s++;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}/*
0 2
5 3
-2 -1 0 -1 2
6 2
-4 -3 -2 -1 3 6
*/
