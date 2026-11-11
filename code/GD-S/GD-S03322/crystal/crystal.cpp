#include<bits/stdc++.h>
using namespace std;
long long n,m;
long double a[500005];
int sum,se=1;
void dfs(int ant,double ne,int pa,int nab)
{
	sum=max(ant,sum);
	if(pa==0)
	{
		return;
	}
	for(int i=nab;i<=n;i++)
	{
		if(a[i]==ne)
		{
			dfs(ant+1,ne,pa,nab+1);
		}
		else if(a[i]+pa>=ne&&a[i]<ne)
		{
			dfs(ant+1,ne,pa-(ne-a[i]+1),nab+1);
		}
		else
		dfs(1,a[nab],m,se++);
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,a[se],m,se);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
