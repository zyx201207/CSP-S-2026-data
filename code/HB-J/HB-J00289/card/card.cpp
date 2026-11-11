#include <bits/stdc++.h>
using namespace std;
const int maxn1=5e5+5,maxn2=3e5+5;
int n,m,a[maxn1],ans[maxn2];
bool vis[maxn2];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis,false,sizeof vis);
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]) while(s.top()!=a[j]&&!s.empty()) vis[s.top()]=false,s.pop();
			else vis[a[j]]=true,s.push(a[j]);
		}
		while(!s.empty()) ans[s.top()]++,s.pop();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
