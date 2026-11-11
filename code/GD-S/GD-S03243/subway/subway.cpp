#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[500005],t[500005];
long long dis[500005];
bool flag[500005];
struct node{
	long long x,len;
	bool operator < (const node &r) const{
		return r.len<len;
	}
};
vector< vector<node> > qq(500005);
priority_queue<node> st;
void solve(long long s,long long t){
	for(int i=1;i<=m;++i) flag[i]=false;
	for(int i=1;i<=m;++i) dis[i]=1e18;
	dis[s]=0;
	st.push({s,0});
	while(!st.empty()){
		node rt=st.top();
		st.pop();
		if(!flag[rt.x]){
			flag[rt.x]=true;
			for(int i=0;i<qq[rt.x].size();++i){
				long long v=qq[rt.x][i].x;
				if(dis[v]>dis[rt.x]+qq[rt.x][i].len){
					dis[v]=dis[rt.x]+qq[rt.x][i].len;
					st.push({v,dis[v]});
				}
			}
		}
	}
	cout<<dis[t]+w[s]+w[t]<<"\n";
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		long long k;
		cin>>k;
		for(int j=1;j<=k;++j) cin>>a[j]>>t[j];
		for(int j=1;j<=k;++j){
			for(int o=1;o<j;++o){
				qq[a[j]].push_back({a[o],t[j]+t[o]});
				qq[a[o]].push_back({a[j],t[j]+t[o]});
			}
		}
	}
	for(int i=1;i<=q;++i){
		long long s,t;
		cin>>s>>t;
		solve(s,t);
	}
	return 0;
}
