#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pii pair<int,int>
int n,m,d,Q,c,k[505],w[500005],ans[100005];
vector<int> v1[500005],v2[500005],a[505],t[505];
pair<pii,int> qu[100005];
int dis[500005];
priority_queue<pii,vector<pii >,greater<pii > > q;
void solve(int s){
	for(int i=1;i<=m;i++) dis[i]=0x3f3f3f3f;
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		int x=q.top().fi,u=q.top().se;
		q.pop();
		if(x>dis[u]) continue;
		for(int i=0;i<v1[u].size();i++){
			int y=v1[u][i],z=v2[u][i];
			for(int j=0;j<a[y].size();j++){
				if(x+t[y][j]+z<dis[a[y][j]]){
					q.push({x+t[y][j]+z,a[y][j]});
					dis[a[y][j]]=x+t[y][j]+z;
				}
			}
		}
	}
}
queue<pii > q2;
void solveB(int s){
	for(int i=1;i<=m;i++) dis[i]=0x3f3f3f3f;
	dis[s]=0;
	q2.push({0,s});
	while(q2.size()){
		int x=q2.front().fi,u=q2.front().se;
		q2.pop();
		if(x>dis[u]) continue;
		for(int i=0;i<v1[u].size();i++){
			int y=v1[u][i],z=v2[u][i];
			for(int j=0;j<a[y].size();j++){
				if(x+t[y][j]+z<dis[a[y][j]]){
					q2.push({x+t[y][j]+z,a[y][j]});
					dis[a[y][j]]=x+t[y][j]+z;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,j1,j2;j<=k[i];j++){
			cin>>j1>>j2;
			a[i].push_back(j1);
			t[i].push_back(j2);
			v1[j1].push_back(i);
			v2[j1].push_back(j2);
		}
	}
	for(int i=1;i<=Q;i++){
		cin>>qu[i].fi.fi>>qu[i].fi.se;qu[i].se=i;
		if(qu[i].fi.se<qu[i].fi.fi) swap(qu[i].fi.fi,qu[i].fi.se);
		}
	sort(qu+1,qu+1+Q);
	for(int i=1;i<=Q;i++){
		if(qu[i].fi.fi!=qu[i-1].fi.fi) {
			if(c>=12 && c<=19) solveB(qu[i].fi.fi);
			else solve(qu[i].fi.fi);
		}
		ans[qu[i].se]=dis[qu[i].fi.se]+w[qu[i].fi.fi]+w[qu[i].fi.se];
	}
	for(int i=1;i<=Q;i++) cout<<ans[i]<<"\n";
}