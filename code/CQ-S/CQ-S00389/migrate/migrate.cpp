#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e6;
int t;
int x[N],n,d;
struct _{
	int d,x;
	friend bool operator<(_ a,_ b){
		return a.d>b.d;
	}
};
vector<int> vc[N];
int ds[N];
int f[N];
bool flg[N];
int dij(int s){
	priority_queue<_> q;
	q.push({0,s});
	memset(ds,0x3f,sizeof ds);
	memset(f,0,sizeof f);
	memset(flg,0,sizeof flg);
	ds[s]=0;
	f[s]=1;
	while(!q.empty()){
		int u=q.top().x,dis=q.top().d;
		q.pop();
		if(flg[u])continue;
		flg[u]=1;
		for(int v:vc[u]){
			if(ds[u]+1<ds[v]){
//				cout<<u<<"change"<<v<<":"<<f[v]<<"to"<<f[u]<<'\n';
				ds[v]=ds[u]+1;
				f[v]=f[u];
				q.push({ds[v],v});
			}
			else if(ds[u]+1==ds[v]){
//				cout<<u<<"add"<<v<<':'<<f[v]<<"to"<<f[u]+f[v]<<'\n';
				f[v]+=f[u];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
//		cout<<f[i]<<' ';
		if(f[i]==2)ans++;
	}
//	cout<<'\n';
	return ans;
}
void mian(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		vc[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(x[i]-x[j])<=d){
//				cout<<i<<"to"<<j<<'\n'; 
				vc[i].push_back(j);
				vc[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		sort(vc[i].begin(),vc[i].end());
		vc[i].erase(unique(vc[i].begin(),vc[i].end()),vc[i].end());
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dij(i);
	}
	cout<<ans/2<<'\n';
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>t;
	while(t--){
		mian();
	}
	return 0;
} 
