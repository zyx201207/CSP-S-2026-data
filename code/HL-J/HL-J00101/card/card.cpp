#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int M=3e5+10;
int a[N];
stack<int> sl;
int js[M];
int ans[M];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(js[a[j]]==0)
			{
				sl.push(a[j]);
				js[a[j]]=1;
			}
			else
			{
				while(sl.top()!=a[j])
				{
					int y=sl.top();
					sl.pop();
					js[y]=0;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(js[j]!=0)
			{
				ans[j]++;
			}
			js[j]=0;
			if(!sl.empty())
			{
				sl.pop();
			}
		}
	}
	for(int j=1;j<=m;j++)
		{
			cout<<ans[j]<<" ";
		}
    return 0;
 }
