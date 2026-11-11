#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int a[200010];
void dfs(int u,vector<int>o[])
{
	vector<int>b[40];
	int k[40];
	memset(k,0,sizeof(k));
	for(int l=0;l<=o[u].size();l++)
	{
		int x=l;
		for(int j=1;x;j++)
			k[j]+=(x%2),x/=2,b[j].push_back(a[j]);//
		for(int i=u-1;i;i--)
		{
			if(k[i]>=m)
			{
//				cout<<i<<"-----"<<endl;
				ans+=(1<<(i-1));
				dfs(i,b);
				return;
			}
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int k[40];
	memset(k,0,sizeof(k));
	vector<int>b[40];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i];
		for(int j=1;x;j++)
			k[j]+=(x%2),x/=2,b[j].push_back(a[i]);
	}
	for(int i=30;i;i--)
		if(k[i]>=m)
		{
			ans+=(1<<(i-1));
			dfs(i,b);
			break;
		}
	cout<<ans;
	return 0;
}
//4 2
//3 15 12 12

