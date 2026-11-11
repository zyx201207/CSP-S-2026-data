#include<bits/stdc++.h>
using namespace std;
struct node{long long idx,s;};
long long c,n,m,d,q,w[500005],book[500005],ans[500005];
vector<node>vec[500005];
long long bfs(long long ss,long long e){
	memset(book,0,sizeof book);
	memset(ans,0x3f,sizeof ans);
	queue<long long>que;
	que.push(ss);
	book[ss]=1;ans[ss]=0;
	for(int i=0;i<vec[ss].size();i++){ans[vec[ss][i].idx]=vec[ss][i].s;}
	while(!que.empty()){
		long long head=que.front();
		book[head]=1;
		que.pop();
		for(int i=0;i<vec[head].size();i++){
			long long w=vec[head][i].s+ans[head];
			long long v=vec[head][i].idx;
			ans[v]=min(ans[v],w);
			if(book[v]==1) continue;
			que.push(v);
			book[v]=1;
		}
	}
	return w[ss]+w[e]+ans[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	// f,xianlu,zhan,f,daan
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		long long t;cin>>t;node tt[500005];
		for(int j=1;j<=t;j++){cin>>tt[j].idx>>tt[j].s;}
		for(int j=1;j<t;j++){
			for(int k=j+1;k<=t;k++){
				vec[tt[j].idx].push_back(node{tt[k].idx,tt[j].s+tt[k].s});
				vec[tt[k].idx].push_back(node{tt[j].idx,tt[j].s+tt[k].s});
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long ss,e;cin>>ss>>e;
		cout<<bfs(ss,e)<<endl;
	}
	return 0;
}

