#include<bits/stdc++.h>
#define int long long
using namespace std;
int cc,n,m,d,q,w[500005];
int dp[500005];
map<pair<int,int>,int> mp;
struct wp{
	int x,y;
};
vector<wp> vec[55],tor[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			vec[i].push_back({a,t});
			tor[a].push_back({i,t});
		}
	}
	for(int ii=1,x,y;ii<=q;ii++){
		cin>>x>>y;
		if(mp[{max(x,y),min(x,y)}]){
			cout<<mp[{max(x,y),min(x,y)}]<<'\n';
			continue;
		}
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push({w[x],x});
		for(int i=1;i<=m;i++)  dp[i]=0x4f4f4f4f4f4f4f4f;
		dp[x]=w[x];
		while(pq.size()){
			int fo=pq.top().first,wh=pq.top().second;
			pq.pop();
			if(fo>dp[wh])  continue;
			else if(wh==y)  break;
			for(int i=0;i<tor[wh].size();i++){
				int o=tor[wh][i].x,oo=tor[wh][i].y;
				for(int j=0;j<vec[o].size();j++){
					int p=vec[o][j].x,pp=vec[o][j].y;
					int nxt=fo+oo+pp;
					if(p==wh||dp[p]<=nxt)  continue;
					dp[p]=nxt;
					pq.push({nxt,p});
				}
			}
		}
		cout<<dp[y]+w[y]<<'\n';
		mp[{max(x,y),min(y,x)}]=dp[y]+w[y];
	}
	return 0;
} 
