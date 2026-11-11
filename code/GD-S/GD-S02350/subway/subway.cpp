#include <bits/stdc++.h>
#define PAIR pair<int,int>
#define int long long
using namespace std;
int c,n,m,d,g; //c测试点，n地铁线路数，m地铁站数，d最多换乘线路数，g询问次数 
int w[500005],up[500005];
int le[500005];
vector<PAIR> f[505]; //first能通往哪里，second站台到轨道时间 
priority_queue<PAIR> q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>g;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			f[i].push_back({a,t});
			up[a]=t;
		}
	}
	while(g--){
		int sta,en,minn=INT_MAX;
		cin>>sta>>en;
		memset(le,0x4f,sizeof(le));
		while(!q.empty()) q.pop();
		le[sta]=w[sta];
		q.push({w[sta],sta});
		while(!q.empty()){
			PAIR t=q.top();
			q.pop();
			if(le[t.second] < t.first){
				continue;
			}
			if(t.second==en) {
				minn=t.first+w[t.second];
				break;
			}
			le[t.second]=t.first;
			for(int i=0;i<f[t.second].size();i++){
				int tfirst=t.first+up[t.second]+f[t.second][i].second;
				q.push({tfirst,f[t.second][i].first});
			}
		}
		cout<<minn<<endl;
	}
	return 0;
}
