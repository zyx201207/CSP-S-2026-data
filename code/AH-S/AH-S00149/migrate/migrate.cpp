#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y;
}n1;
int t,n,m,a[2000005],vis[2000005];
bool bfs(int xx,int yy){
	int mn=1e9;
	for(int i=1; i<=n; i++)
		vis[i]=0;
	queue <node> q;
	q.push({xx,0});
	while(!q.empty())
	{
		n1=q.front();
		q.pop();
		if(n1.x==yy)
		{
			mn=min(mn,n1.y);
			vis[n1.y]++;
			continue;
		}
		int s=0;
		for(int i=n1.x+1; i<=n; s+=a[i]-a[i-1],i++)
			if(s+a[i]-a[i-1]<=m)
				q.push({i,n1.y+1});
	}
	if(mn==1e9) return 0;
	return vis[mn]==2;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>t;
	while(t--)
	{
		int s=0;
		cin>>n>>m;
		for(int i=1; i<=n; i++)
			cin>>a[i];
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				if(bfs(i,j))
					s++;
		cout<<s<<"\n";
	}
	return 0;
}
