#include<bits/stdc++.h>
using namespace std;
#define int long long
using p=pair<int,int>;
constexpr int N=1000009;
int fa[N];
int vis[N];
int vis1[N];
vector<int> edge[N];
vector<int> son[N];
int n,k;
void get_fa_son(int idx){
	for(int i=0;i<edge[idx].size();i++){
		int ne=edge[idx][i];
		son[idx].push_back(ne);
		fa[ne]=idx;
		get_fa_son(ne);
	}
	cout<<idx<<' '<<son[idx].size()<<endl;
}
int get_lent(int first,int second){
	deque<int> q;
	q.push_front(first);
	q.push_front(second);
	for(int i=1;i<=n;i++){
		vis1[i]=-1;
	}
	vis1[first]=vis1[second]=0;
	int ma=0;
	while(!q.empty()){
		int a=q.front();
		for(int i=0;i<edge[a].size();i++){
			int ne=edge[a][i];
			if(vis1[ne]==-1){
				continue;	
			}
			else{
				if(vis[ne]){
					vis1[ne]=vis1[a];
					q.push_front(ne);
				}
				else{
					vis1[ne]=vis1[a]+1;
					q.push_back(ne);
				}
				ma=max(ma,vis1[ne]);
			}
		}
	}
	return ma;
}
int get(int idx,int sum,int cnt,int first,int second){
	if(cnt>2){
		return 1e14;
	}
	if(sum==k){
		return get_lent(first,second);
	}
	int ans=1e14;
	vis[0]=0;
	for(int i=0;i<son[idx].size();i++){
		int ne=son[idx][i];
		vis[idx]=1;
		int ne_sum=sum+1;
		int ne_cnt=cnt;
		if(!vis[fa[idx]]) ne_cnt++;
		int ne_first;
		if(first==0) ne_first=idx;
		else ne_first=first;
		int ne_second;
		if(!vis[fa[idx]] && ne_cnt==2) ne_second=idx;
		else ne_second=second;
		ans=min(ans,get(ne,ne_sum,ne_cnt,ne_first,ne_second));
		ne_cnt=cnt;
		ne_first=first;
		ne_second=second;
		ne_sum=sum;
		vis[idx]=0;
		ans=min(ans,get(ne,ne_sum,ne_cnt,ne_first,ne_second));
	}
	return ans;
}
void solve(){
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	get_fa_son(1);
	if(k>=n){
		cout<<0<<endl;
		return;
	}
	if(k==n-1){
		cout<<1<<endl;
		return;
	}
	cout<<get(1,0,0,0,0)<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,_;
	cin>>c>>_;
	while(_--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
