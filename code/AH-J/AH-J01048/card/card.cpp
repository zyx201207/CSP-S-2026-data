#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int a[10005];
int f[10005];
deque<int> q;
int s[10005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) f[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==1)
			{
				while(!q.empty()&&a[j]!=a[q.back()])
				{
					f[a[q.back()]]--;
					q.pop_back();
				}
			}
			else q.push_back(j),f[a[j]]++;
		}
		while(!q.empty()) 
		{
			s[a[q.back()]]++;
			q.pop_back();
		}
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}
