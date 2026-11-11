#include<bits/stdc++.h>
#define int long long
#define pll pair<int,int>
using namespace std;
const int N=1e6+5;
vector<int>a[N];
int c,t,n,d,ans,p[N];
bool b[N];
int find(int x){
	if(x==p[x])return x;
	else return p[x]=find(p[x]);
}
int dd(int x){
	priority_queue<pll,vector<pll>,greater<pll>>q;
	int dist[N];
	memset(dist,0x3f,sizeof dist);
	q.push({0,x});
	dist[x]=0;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		for(auto e:a[u]){
			if(dist[e]>=dist[u]+1){
				dist[e]=dist[u]+1;
				q.push({dist[e],e});
			} 
		}
	}
	int k=2e9;
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	queue<int>qq;
	qq.push(x);
	bool bb[N];
	memset(bb,0,sizeof bb);
	bb[x]=1;
	qq.push(x);
	while(qq.size()){
		int u=qq.front();
		qq.pop();
		for(auto e:a[u]){
			if(!bb[e]){
				p[e]=u;
				bb[e]=1;
				qq.push(e);
			}
		}
	}
	int aa,bbb;
	aa=bbb=0;
	for(int i=1;i<=n;i++){
		if(b[i]){
			k=min(k,dist[i]);
		}else{
			if(aa==0){
				aa=find(p[i]);
			}else{
				if(bbb==0){
					bbb=find(p[i]);
				}else{
				if(aa==find(p[i])||bbb==find(p[i])){
					continue;
				}else return 0x3f3f3f3f;
				}
			}
		}
		
	}
	return k;
}
void dfs(int x,int cnt){
	if(cnt>d)return ;
	if(x>n){
		if(cnt<d)return ;
		int sum=0;
		for(int i=1;i<=n;i++){
			sum=max(sum,dd(i));
		}
		ans=min(ans,sum);
		return ;
	}
	b[x]=0;
	dfs(x+1,cnt);
	b[x]=1;
	dfs(x+1,cnt+1);
}
signed main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		ans=2e9;
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
