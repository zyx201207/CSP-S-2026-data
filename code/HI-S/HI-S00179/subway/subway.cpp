#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int k[501],v[500001][500001],f[500001];
int vis[500001];
struct node{
	int w,t;
}a[500001];
struct dj{
	int x,y;
};
queue<dj>q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i].w;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int ji=0;
		for(int j=1;j<=k[i];j++){
			int id;
			cin>>id;
			cin>>a[id].t;
			v[ji][id]=v[id][ji]=a[id].t+a[id].w+a[ji].t+a[ji].w;
			ji=id;
		}
	}
	while(p--){
		int s,e;
		cin>>s>>e;
		memset(vis,0x3f,sizeof(vis));
		q.push({s,0});
		f[s]=1;
		while(!q.empty()){
			dj h=q.front();
			q.pop();
			for(int i=1;i<=m;i++){
				if(v[h.x][i]&&f[i]==0&&v[h.x][i]+h.y<vis[i]){
					vis[i]=v[h.x][i]+h.y;
					q.push({i,vis[i]});
					f[i]=1;
				}
			}
		}
		cout<<vis[e]<<'\n';
	}
	return 0;
}
