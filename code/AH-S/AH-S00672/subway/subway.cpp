#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=5e5+7;
const long long INF=LLONG_MAX;
int a[N],times[N],stations[N];
int c,n,m,d,q;
struct node{
	int to,ty,w;
};
vector<node> g[N];
vector<int> t[N];
int flag[N];
void dfs(int root,int step,int type,int w){
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>stations[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>times[j];
		}
		for(int j=1;j<k;j++){
			g[a[j]].push_back({a[j+1],i,0});
			g[a[j+1]].push_back({a[j],i,0});
			t[a[j]].push_back(times[j]);
		}
		t[a[k]].push_back(times[k]);
	}
	for(int i=1;i<=m;i++){
		int len=g[i].size();
		for(int j=0;j<len;j++){
			cout<<g[i][j].to<<" ";
		}
		cout<<"\n";
		int len2=t[i].size();
		for(int j=0;j<len2;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<"\n";
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}
