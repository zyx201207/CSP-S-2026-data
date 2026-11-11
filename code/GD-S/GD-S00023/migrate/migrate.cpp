#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d,a[N],cnt[N];
vector<int> b[N];
int dis[N],ans;
bool vis[N];
struct node{
	int bi,ch;
	bool operator<(const node &q)const{
		return q.ch<ch;
	}
};
void dij(int s)	{
	priority_queue<node> q;
	q.push({s,0});
	for(int i=1;i<=n;i++){
		dis[i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
		cnt[i]=1;
	}
	dis[s] =0; 
	while(!q.empty())	{
		int x=q.top().bi;
		q.pop();
		if(vis[x])	continue;
		vis[x]=1;
		for(int i=0;i<(int)b[x].size();i++)	{
			int y=b[x][i];
			if(dis[y]>dis[x]+1)	{
				cnt[y]=cnt[x];
				dis[y]=dis[x]+1;
				q.push({y,dis[y]});
			}
			else if(dis[y]==dis[x]+1)	cnt[y] += cnt[x];
		}
	}
}
void cintie()	{
	cin>>n>>d;
	for(int i=1;i<=n;i++)	{
		cin>>a[i];
		b[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)	{
			if(abs(a[i]-a[j])<=d)		b[i].push_back(j);
		}
	}
	ans=0;
	for(int i=1;i<=n;i++)	{
		dij(i);
		for(int j=i+1;j<=n;j++)		ans+=(cnt[j]==2);
	}
	cout<<ans<<'\n';
}
signed main()	{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c;
	for(cin>>T;T--;)	cintie();
	
	return 0;
}
/*
0 1
4 2 
1 2 3 4
5 2
1 2 3 4 5

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
