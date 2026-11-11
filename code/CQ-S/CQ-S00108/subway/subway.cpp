#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[500100];//
struct noo{
	int sum;
	vector<int> a,t;
}lne[510];
int zhi[500100];
int dp[510][510];// line ->line
struct nn{
	vector<int> ll;
	vector<int> ttll;
}sta[500100];
struct bb{
	int id,cost;
	bool operator <(const bb &ot)const{
		cost>ot.cost;
	}
};
int dfs(int qi,int zd){
//	if(dp[qi][zd]!=LLONG_MAX){
//		return dp[qi][zd];
//	}
	priority_queue<bb> q;
 q.push({qi,0});
 	while(!q.empty()){
 		bb qw=q.top();
 		q.pop();
// 		if(qw.id==zd){
// 			return dp[qi][qw.id];
//		}
		for(int i=1;i<=n;i++){
			if(i!=qw.id&&dp[i][qw.id]!=LLONG_MAX){
				if(dp[i][qi]>=dp[i][qw.id]+qw.cost){
					dp[qi][i]=dp[i][qi]=dp[i][qw.id]+qw.cost;
					q.push({i,dp[i][qw.id]+qw.cost});
				}
			}
		}
	}
	return dp[qi][zd];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>lne[i].sum;
		for(int j=1;j<=lne[i].sum;j++){
			int aa,tt;
			cin>>aa>>tt;
			lne[i].a.push_back(aa);
			lne[i].t.push_back(tt);
			sta[aa].ll.push_back(i);
			sta[aa].ttll.push_back(tt);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=LLONG_MAX;
			if(i==j){
				dp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int k=0;k<sta[i].ll.size();k++){
			for(int j=k+1;j<sta[i].ll.size();j++){
				dp[sta[i].ll[k]][sta[i].ll[j]]=min(dp[sta[i].ll[k]][sta[i].ll[j]],sta[i].ttll[k]+sta[i].ttll[j]);
				dp[sta[i].ll[j]][sta[i].ll[k]]=dp[sta[i].ll[k]][sta[i].ll[j]];
			}
		} 
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		int ans=LLONG_MAX;
		for(int it=0;it<sta[st].ll.size();it++){
			for(int iit=0;iit<sta[ed].ll.size();iit++){
				
				ans=min(ans,dfs(sta[st].ll[it],sta[ed].ll[iit])+sta[st].ttll[it]+sta[ed].ttll[iit]+w[st]+w[ed]);
			}
		}
		cout<<ans<<"\n";
	}
}
