#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+10;
int w[M],dd[M];
vector<pair<int,int>> a[500];
struct node{
	vector<pair<int,int>> s;
}cc[M];
void dij(int x){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	memset(dd,0x3f,sizeof dd);
	dd[x]=0,q.emplace(0,x);
	while(q.size()){
		auto tt=q.top();
		q.pop();
		if(tt.first>dd[tt.second]) continue;
		for(auto y:cc[tt.second].s){
			for(auto yy:a[y.first]){
				if(yy.first==tt.second) continue;
				if(dd[yy.first]>tt.first+yy.second){
//					if(dd[tt.second]==0) 
					dd[yy.first]=tt.first+yy.second+y.second,q.emplace(dd[yy.first],yy.first);
//					else dd[yy.first]=tt.first+yy.second,q.emplace(dd[yy.first],yy.first);
//					cout<<tt.second<<" "<<yy.first<<" "<<dd[yy.first]<<"\n";
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t,tt;
			cin>>t>>tt;
			a[i].push_back({t,tt});
			cc[t].s.push_back({i,tt});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dd[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
