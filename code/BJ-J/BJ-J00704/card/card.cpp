#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int a[N],ans[N];
bool vis[N];
stack<int>s;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])s.push(a[j]),vis[a[j]]=true;
			else while(s.top()!=a[j]&&s.size()>0) vis[s.top()]=false,s.pop();
		}
		while(s.size()>0) ans[s.top()]++,vis[s.top()]=false,s.pop();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
