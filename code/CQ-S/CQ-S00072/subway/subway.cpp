#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int mid,ll,rr,b,z,w,l,r,p,c,n,m,d,q,a[500005],dis[1000005],vis[1000005];
vector<pair<int,int> > v[1000005];
bool flag[500005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
queue<int> qq;
int Dijkstra(){
	if(flag[l]){
		return v[l][r-1-(r>l)].first+a[l]+a[r];
	}
	flag[l]=1;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	pq.push({0,l});
	dis[l]=0;
	while(!pq.empty()){
		b=pq.top().second;
		pq.pop();
		if(vis[b]){
			continue;
		}
		vis[b]=1;
		for(int i=0;i<v[b].size();i++){
			if(dis[v[b][i].second]>dis[b]+v[b][i].first){
				dis[v[b][i].second]=dis[b]+v[b][i].first;
				pq.push({dis[v[b][i].second],v[b][i].second});
			}
		}
	}
	v[l].clear();
	for(int i=1;i<=m;i++){
		if(i!=l){
			v[l].push_back({dis[i],i});
		}
	}
	return a[l]+a[r]+dis[r];
}
void bfs(){
	memset(dis,0,sizeof(dis));
	dis[l]=0;
	qq.push(l);
	while(!qq.empty()){
		b=qq.front();
		qq.pop();
		for(int i=0;i<v[b].size();i++){
			if(v[b][i].second!=l&&!dis[v[b][i].second]){
				dis[v[b][i].second]=dis[b]+1;
				if(v[b][i].second==r){
					cout<<dis[b]+1+a[l]+a[r]<<endl;
					while(!qq.empty()){
						qq.pop();
					}
					return ;
				}
				qq.push(v[b][i].second);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p;
		if(p==1){
			cin>>z>>w;
			continue;
		}
		else if(p==2&&7<=c<=11){
			cin>>z>>w>>l>>r;
			v[z].push_back({r+w,l});
			v[l].push_back({r+w,z});
			continue;
		}
		for(int j=1;j<=p;j++){
			cin>>z>>w;
			if(12<=c&&c<=19){
				v[m+i].push_back({1,z});
				v[z].push_back({1,m+i});
			}
			else{
				v[m+i].push_back({w,z});
				v[z].push_back({w,m+i});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		if(12<=c&&c<=19){
			bfs();
		}
		else{
			if(flag[r]){
				swap(l,r);
			}
			cout<<Dijkstra()<<endl;
		}
	}
	return 0;
}
/*
预期48,希望CCF机子跑快点
*/
