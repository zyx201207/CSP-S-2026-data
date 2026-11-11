#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
long long c,n,m,d,q;//测试点编号，地铁线路数，地铁站数，每个站最多几条线路，出行计划数 
long long k;
const int MXN=5e5+1,MXN1=1e5+1;
int subto[MXN],way_zhan[505][MXN1],way_time[505][MXN1],start,to;
struct subway{
	int xianlu,to_zhan,time;
};
vector<subway>v[MXN];
void solve(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	int nodexianlu[MXN];
	q.push({subto[start],start});
	bool vis[MXN];
	int small[MXN];
	while(q.size()){
		pair<int,int> p=q.top();
		q.pop();
		if(p.second==to){
			cout<<p.first+subto[p.second]<<endl;
			return;
		}
		small[p.second]=p.first;//first:time,second:编号 
		vis[p.second]=true;
		int fst=p.first,lst=p.second;
		for(int i=0;i<v[lst].size();++i){
			if(vis[v[lst][i].to_zhan])continue;
			else{
				q.push({p.first,v[lst][i].to_zhan});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>subto[i];
	} 
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>way_zhan[i][j]>>way_time[i][j];
			if(j!=2){
				v[way_zhan[i][j]].push_back({i,way_zhan[i][j-1],way_time[i][j-1]});//第i个线路+链接第几站+这个线路的这个站台上到站厅要多久 
				v[way_zhan[i][j-1]].push_back({i,way_zhan[i][j],way_time[i][j]});
			}
		}
	}
	for(int i=1;i<=q;++i){
		cin>>start>>to;
		solve();
	}
	return 0;
}
