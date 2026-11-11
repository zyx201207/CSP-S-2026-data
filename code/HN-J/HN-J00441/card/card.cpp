#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;

int n,m;
int a[N],dis[N],ans[N];
bool vis[N];

queue<int> q;

void play(int I)
{
	q.push(a[I]);
	
	int i=I;
	while(!q.empty())
	{
		if(i==n)
		{
			while(!q.empty())
			{
				ans[q.front()]++;
				q.pop();
			}
		}
		
		if(!vis[a[i]])
		{
			q.push(a[i]);
			vis[a[i]]=true;
		}
		else
		{
			while(!q.empty() && q.front()!=a[i])
			{
				vis[a[i]]=false;
				q.pop();
			}
			if(!q.empty() && q.front()==a[i])
			{
				vis[a[i]]=false;
				q.pop();
			}
		}
		i++;
	}	
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i]=vis[i]=0; 
		while(!q.empty()) q.pop();
		play(i);
	}
	
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
