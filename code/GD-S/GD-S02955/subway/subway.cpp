#include <bits/stdc++.h>
using namespace std;
const int N=600005;
int c,n,m,d,q,w[505],k[505],cnt;
vector<pair<int,int> > rel[N];
vector<int> line[N];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq; 
//分层图 
int dp[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	cnt=m;
	for(int i=1;i<=m;i++) cin>>w[i];
//
	if(c<=6){
		for(int i=1;i<=n;i++){//第i条线路 
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			cnt++;
			line[i].push_back(cnt);
			rel[a].push_back({t,cnt});
			rel[cnt].push_back({t,a});
		}
		for(int j=0;j<k;j++){
			for(int g=0;g<k;g++){
				if(j==g) continue;
				rel[line[i][j]].push_back({0,line[i][g]});
			}
		}
	}
	//dijskra
	for(int g=1;g<=q;g++){
		int s,e;
		cin>>s>>e;
		while(!pq.empty()) pq.pop();
		pq.push({-1,{0,s}});
		for(int i=0;i<=N;i++) dp[i]=1e9;
		dp[s]=0;
		while(pq.empty()==0){
			pair<int,pair<int,int> > p=pq.top();
			pq.pop();
			int fa=p.first,u=p.second.second,len=p.second.first;
			if(len>dp[u]) continue;
			for(auto i:rel[u]){
				int v=i.second,w=i.first;
				if(v==fa) continue;
				if(dp[v]>dp[u]+w){
					dp[v]=dp[u]+w;
					pq.push({u,{dp[v],v}});
				}
			}
		}
		cout<<w[s]+dp[e]+w[e]<<endl;
	}
	}
//
	else if(c<=11){
		for(int i=1;i<=n;i++){//第i条线路 
			int k;
			cin>>k;
			int a1,a2,t1,t2;
			cin>>a1>>t1>>a2>>t2;
			rel[a1].push_back({t1+t2,a2});
	}
	//dijskra
	for(int g=1;g<=q;g++){
		int s,e;
		cin>>s>>e;
		while(!pq.empty()) pq.pop();
		pq.push({-1,{0,s}});
		for(int i=0;i<=m;i++) dp[i]=1e9;
		dp[s]=0;
		while(pq.empty()==0){
			pair<int,pair<int,int> > p=pq.top();
			pq.pop();
			int fa=p.first,u=p.second.second,len=p.second.first;
			if(len>dp[u]) continue;
			for(auto i:rel[u]){
				int v=i.second,w=i.first;
				if(v==fa) continue;
				if(dp[v]>dp[u]+w){
					dp[v]=dp[u]+w;
					pq.push({u,{dp[v],v}});
				}
			}
		}
		cout<<w[s]+dp[e]+w[e]<<endl;
	}
	}
}
