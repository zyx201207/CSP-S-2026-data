#include<bits/stdc++.h>//暴力 
using namespace std;
struct zhan{
	int ok,t1me;
};
struct zhan1{
	int where,sumt1me;
};
vector<zhan> v[25];//每个站能去的及时间 
vector<zhan> khc[25];//可换乘？ 
int w[500005];
bool vis[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,T;
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<int> ttto(n+5,0);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		vector<int> a(x+2,0),t(x+2,0);
		for(int j=1;j<=x;j++){
			int t1,a1;//时间，站台 
			cin>>a1>>t1;
			t[j]=t1;
			a[j]=a1;
		}
		for(int j=1;j<x;j++){
			v[a[j]].push_back({a[j+1],t[j+1]});
			v[a[j+1]].push_back({a[j],t[j]});
			khc[a[j]].push_back({a[j],t[j]});
			ttto[a[j]]++;
		}
	}
	while(T--){
		int s,e;
		cin>>s>>e;
		queue<zhan1> q;
		for(int i=1;i<=m;i++){
			for(auto u:v[i]){
				if(u.ok==s){
					q.push({u.ok,w[u.ok]+u.t1me});
				}
			}
		}
		int ans=INT_MAX;
		while(!q.empty()){
			auto temp=q.front();
			q.pop();
			if(temp.where==e){
				ans=min(ans,temp.sumt1me)+w[e]; 
			}
			if(ttto[temp.where]&&vis[temp.where]==0){
				for(auto u:khc[temp.where]){
					temp.sumt1me+=u.t1me;
				}
				vis[temp.where]=1;
			}
			for(auto u:v[temp.where]){
				q.push({temp.where,temp.sumt1me});
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
