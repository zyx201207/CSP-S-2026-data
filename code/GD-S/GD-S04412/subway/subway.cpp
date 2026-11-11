#include<bits/stdc++.h>
using namespace std;
struct t{
	long long time;
	long long next;
};
const int M=5e5+550;
vector<t> node[M];
long long w[M];
bool operator < (const t a,const t b){
	return a.time<b.time;
}
long long dis[M];

long long djs(int st,int ed){
	priority_queue<t> qu;
	memset(dis,127,sizeof(dis));
	qu.push({0,st});
	dis[st]=0;
	while(!qu.empty()){
		t pt=qu.top();
		qu.pop();
		for(auto e:node[pt.next]){
			if(dis[pt.next]+e.time<dis[e.next]){
				dis[e.next]=dis[pt.next]+e.time;
				qu.push({dis[e.next],e.next});
			}
		}
	}
	return dis[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int stn,tm;
			cin>>stn>>tm;
			node[stn].push_back({tm,i+m});
			node[i+m].push_back({tm,stn});
		}
	}
	
	while(q--){
		int st,ed;
		cin>>st>>ed;
		long long ans=djs(st,ed)+w[st]+w[ed];
		cout<<ans<<endl;
	}
} 

