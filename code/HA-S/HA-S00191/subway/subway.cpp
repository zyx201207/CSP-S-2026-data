#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+9;
int c,n,m,d,q,w[maxn],t[maxn][25];
struct node{
	int id,next;
};
vector<node>a[maxn];
//vector<int>track[maxn];
//struct sw{
//	int id_1,id_2,path;
//	friend bool operator < (sw x,sw y){
//		return x.path>y.path;
//	}
//};
//priority_queue<sw>pq;
map<int,bool>visited;
int dfs(int idx,int Start,int now,int End){
	if(now==End)return t[End][idx]+w[End];
	int ans=0;
	for(int i=0;i<a[now].size();i++){
		if(visited.count(a[now][i].next))continue;
		if(a[now][i].id==idx){
			visited[a[now][i].next]=1;
			if(ans==0) ans=dfs(idx,Start,a[now][i].next,End);
			else ans=min(ans,dfs(idx,Start,a[now][i].next,End));
			visited[a[now][i].next]=0;
		}else{
			int delta_t=t[now][idx]+t[now][a[now][i].id];
			visited[a[now][i].next]=1;
			if(ans==0)ans=delta_t+dfs(a[now][i].id,Start,a[now][i].next,End);
			else ans=min(ans,delta_t+dfs(a[now][i].id,Start,a[now][i].next,End));
			visited[a[now][i].next]=0;
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int ki,a_0=0;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int ai,ti;
			cin>>ai>>ti;
			//track[ai].push_back(i);
			t[ai][i]=ti;
			if(a_0==0){a_0=ai;continue;}
			else a[a_0].push_back({i,ai}),a[ai].push_back({i,a_0}),a_0=ai;
		}
	}
	for(int i=1;i<=q;i++){
		int xr,yr;
		cin>>xr>>yr;
		int ansi=0;
		for(int j=0;j<a[xr].size();j++){
			visited[xr]=1;
			int ppp=dfs(a[xr][j].id,xr,a[xr][j].next,yr);
			if(ansi==0){
				if(ppp) visited[a[xr][j].next]=1,ansi=t[xr][a[xr][j].id]+w[xr]+ppp;
			} 
			else{
				if(ppp)visited[a[xr][j].next]=1,ansi=min(ansi,t[xr][a[xr][j].id]+w[xr]+ppp);
			}
			visited.clear();
		}
		visited.clear();
		cout<<ansi<<"\n";
	}
	return 0;
}

