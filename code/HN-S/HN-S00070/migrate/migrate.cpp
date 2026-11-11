#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
const int N=1e6+10;
int c;
int t,n;
long long d;
long long a[N];
struct Node{
	long long id,v;
};
Node dis[N];
int bfs(int st){
	int cnt=0;
	for(int i=st;i<=n;i++)dis[i]={0,inf};
	queue<Node>q;
	dis[st]={0,0};
	q.push({st,0});
	while(!q.empty()){
		Node u=q.front();q.pop();
		for(int i=u.id;a[i]<=a[u.id]+d&&i<=n;i++){
			int v=i;
			if(u.v+1<=dis[v].v){
				dis[v].id++;
				dis[v].v=u.v+1;
				q.push({v,u.v+1});
			}
		}
	}for(int i=st;i<=n;i++){
		if(dis[i].id==2)cnt++;
	}return cnt;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++)ans+=bfs(i);
		cout<<ans<<endl;
	}
	return 0;
}

