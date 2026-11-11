#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[500005];
bool vis[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(n<=5000){
		stack<int>s;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			if(!vis[a[j]])
			s.push(a[j]),vis[a[j]]=1;
			else
			{
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}
			while(!s.empty()){
				ans[s.top()]++;
				vis[s.top()]=0;
				s.pop();
			}
		}
		for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	}
	return 0;
}
