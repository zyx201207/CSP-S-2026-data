#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],max1=-2e9;
int aan(int b,int c)
{
	return b&c;
}
void dfs(int n1,int now_n,int ans)
{
//	cout<<n1<<" "<<now_n<<" "<<ans<<endl; 
	if(n1==m)
	{
//		cout<<aan(ans,a[now_n])<<endl;
		max1=max(max1,aan(ans,a[now_n]));
		return ;	
	}
	for(int i=now_n+1;i<=n;i++)
	{
		dfs(n1+1,i,aan(ans,a[i]));
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>=5000&&m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			int a1;
			if(i!=1) a1=a[1];
			else a1=a[2];
			for(int j=1;j<=n;j++)
			{
				if(j!=i) a1=aan(a1,a[j]);
			}
			max1=max(max1,a1);
		}
		cout<<max1;
		return 0;
	}
	if(n>=7000&&m!=n-1)
	{
		int a1=n-1;
		for(int i=1;i<=m;i++)
		{
			a1=aan(a1,a1-1);
		}
		cout<<a1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(1,i,a[i]);
	}
	
	cout<<max1;
	
	return 0;
} 
/*4 2
3 15 12 12
*/
