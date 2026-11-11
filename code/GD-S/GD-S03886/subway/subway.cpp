#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,int> 

const int M=5e5+7,N=507;
int c,n,m,d,q,w[M];
vector<pii> v[M],r[N];
ll dis[N];

ll dijstra(int st,int ed){
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	memset(dis,0x7f,sizeof(dis));
	pq.push({0,st});
	dis[st]=0;
	while(!pq.empty()){
		int p=pq.top().second;
		pq.pop();
		if(p==ed)return dis[p];
		for(auto it:v[p]){
			int rd=it.second;
			ll cost=it.first;
			for(auto jt:r[rd]){
				int to=jt.second;
				ll cnt=jt.first+cost+dis[p];
				if(cnt>=dis[to]) continue;
				dis[to]=cnt;
				pq.push({cnt,to});
			}
		}
	}
	return dis[ed];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,x,y;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			v[x].push_back({y,i});
			r[i].push_back({y,x});
		}
	}
	for(int i=1,st,ed;i<=q;i++){
		cin>>st>>ed;
		ll cnt=dijstra(st,ed)+w[st]+w[ed];
		cout<<cnt<<"\n";
	}
	return 0;
}
