#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[500005];
int s[500005];
int dd[500005];
int a[500005],tt[500005];
struct node{
	int x,w;
	bool operator <(const node &a)const{
		return w>a.w;
	}
};
vector<node>p[500005];
bool vis[500005];
bool o[500005];
int dij(int l,int r){
	priority_queue<node>q;
	q.push({l,0});
	memset(dd,127,sizeof(dd));
	memset(vis,0,sizeof(vis));
	dd[l]=0;
	while(q.size()){
		node x=q.top();
		q.pop();
		if(vis[x.x])continue;
		vis[x.x]=1;
		for(auto y:p[x.x]){
			if(!vis[y.x] && dd[y.x]>dd[x.x]+y.w){
				dd[y.x]=dd[x.x]+y.w;
				q.push({y.x,dd[y.x]});
			}
		}
	}
	return dd[r];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int cnt=1;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i]>>tt[i];
		for(int j=1;j<=k[i];j++){
			if(a[j]==i)s[i]=tt[j];
			if((j==1 || j==k[i]) && o[a[j]]){
				p[a[j]].push_back({m+cnt,0});
				p[m+cnt].push_back({a[j],s[a[j]]});
				if(j==1){
					p[a[j+1]].push_back({m+cnt,0});
					p[m+cnt].push_back({a[j+1],s[a[j]]});
				}else{
					p[a[j-1]].push_back({m+cnt,0});
					p[m+cnt].push_back({a[j-1],s[a[j]]});
				}
				cnt++;
			}else
			p[i].push_back({a[j],tt[j]});
			p[a[j]].push_back({i,tt[j]});
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<dij(l,r)+w[l]+w[r]+s[l]<<'\n';
	}
	return 0;
}
