#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int ans[N];
bool b[N];
int n,m;
int cnt;
int an;
void dfs(int t,int step,int nu)
{
	if(step==m)
	{
		ans[++cnt]=nu;
		return;
	}
	int i;
	for(i=t+1;i<=n;i++)
	{
		if(b[i]==false)
		{
			b[i]=true;
			int temp=nu&a[i];
			dfs(i,step+1,temp);
			b[i]=false;
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		dfs(i,1,a[i]);
	}
	for(i=1;i<=cnt;i++)
	{
		an=max(an,ans[i]);
	}
	cout<<an;
	return 0;
 } 
