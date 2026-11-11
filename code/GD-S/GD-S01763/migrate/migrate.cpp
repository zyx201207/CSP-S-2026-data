#include<bits/stdc++.h>
using namespace std;
long long a[2000002],d;
int n;
int goed[2000002];
int shortest[2000002];
int seach(int x)
{
	memset(goed,0,sizeof goed);
	memset(shortest,0x3f,sizeof shortest);
	queue<pair<int,int>>q;
	q.push({x,0});
	while(!q.empty())
	{
		auto[u,w]=q.front();
		q.pop();
		goed[u]++;
		const int au=a[u];
		w++;
		for(int i=u+1;i<=n&&a[i]-au<=d;i++)
			if(w==shortest[i])
				q.push({i,w});
			else if(w<shortest[i])
				shortest[i]=w,
				q.push({i,w});
	}
	int res=0;
	for(int i=x+1;i<=n;i++)
		res+=(goed[i]==2);
	return res;
}
int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t,ans;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ans=0;
		for(int i=1;i<n;i++)
			ans+=seach(i);
		cout<<ans<<"\n";
	}
	return 0;
}
