#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int N=2e6+114;
vector<int> e[N];
int dep[N];
int mxl=0;
void dfs(int d,int f=0){
	dep[d]=0;
	int mx=0,mx2=0;
	for(int i:e[d]){
		if(i!=f){
			dfs(i,d);
			dep[d]=max(dep[d],dep[i]+1);
			if(dep[i]+1>mx){
				mx2=mx;
				mx=dep[i]+1;
			}
			else{
				mx2=max(mx2,dep[i]+1);
			}
		}
	}
	mxl=max(mxl,mx+mx2);
}
int dt1=0,dt2=0;
void dfs2(int d,int f=0,int len=0){
	int mx=len,hs=0,mx2=0;
	for(int i:e[d]){
		if(i!=f){
			if(dep[i]+1>mx){
				hs=i;
				mx2=mx;
				mx=dep[i]+1;
			}
			else{
				mx2=max(mx2,dep[i]+1);
			}
		}
	}
	if(mx>=mxl/2 and mx2>=mxl/2){
		dt1=d;
		if(hs==0)dt2=f;
		else dt2=hs;
	}
	for(int i:e[d]){
		if(i!=f){
			if(i==hs)dfs2(i,d,mx2+1);
			else dfs2(i,d,mx+1);
		}
	}
}
int hch=0,v=1e9;
void dfs3(int d,int f=0,int len=0){
	int mx=len,hs=0,mx2=0;
	for(int i:e[d]){
		if(i!=f){
			if(dep[i]+1>mx){
				hs=i;
				mx2=mx;
				mx=dep[i]+1;
			}
			else{
				mx2=max(mx2,dep[i]+1);
			}
		}
	}
	if(mx<v){
		v=mx;
		hch=d;
	}
	for(int i:e[d]){
		if(i!=f){
			if(i==hs)dfs3(i,d,mx2+1);
			else dfs3(i,d,mx+1);
		}
	}
}
struct no{
	int d,v;
	bool operator<(const no&b)const{
		return v<b.v;
	}
};
bool vis[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,kk;
		cin>>n>>kk;
		for(int i=1;i<=n;i++){
			vector<int> vv;
			vv.swap(e[i]);
			dep[i]=0;
			vis[i]=0;
		}
		mxl=0;
		dt1=dt2=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1);
		dfs2(1);
		for(int i=0;i<e[dt1].size();i++){
			if(e[dt1][i]==dt2){
				swap(e[dt1][i],e[dt1][e[dt1].size()-1]);
				e[dt1].pop_back();
				break;
			}
		}
		for(int i=0;i<e[dt2].size();i++){
			if(e[dt2][i]==dt1){
				swap(e[dt2][i],e[dt2][e[dt2].size()-1]);
				e[dt2].pop_back();
				break;
			}
		}
		int d1,d2;
		hch=0,v=1e9;
		dfs(dt1);
		dfs3(dt1);
		d1=hch;
		hch=0,v=1e9;
		dfs(dt2);
		dfs3(dt2);
		d2=hch;
		
		dfs(d1);dfs(d2);
		vis[d1]=1;vis[d2]=1;
		priority_queue<no> q;
		for(int i:e[d1]){
			vis[i]=1;
			q.push({i,dep[i]});
		}
		for(int i:e[d2]){
			vis[i]=1;
			q.push({i,dep[i]});
		}
		kk-=2;
		while(q.size() and kk>0){
			kk--;
			int d=q.top().d;
			q.pop();
			for(int i:e[d]){
				if(!vis[i]){
					vis[i]=1;
					q.push({i,dep[i]});
				}
			}
		}
		if(q.empty()){
			cout<<0<<'\n';
		}
		else{
			cout<<q.top().v+1<<'\n';
		}
	}
	return 0;
}
