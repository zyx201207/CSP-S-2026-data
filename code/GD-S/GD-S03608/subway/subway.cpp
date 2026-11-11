#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,M=5e5+10;
int w[M],t[M][N],v[N],n,m;
vector<int> e[M];
vector<int> nd[M];
ll ans;
void dfs(int l,int ed,ll dis){
	bool f=0;
	for(int i:nd[ed]){
		if(l==i){
			ans=min(ans,dis+w[ed]+t[ed][i]);
			f=1;
			break;
		} 
	} 
	if(!f){
		for(int i:e[l]){
			if(nd[i].size()>1){
				for(int j:nd[i]){
					if(v[j]) continue;
					v[j]=1;
					dfs(j,ed,dis+t[i][j]+t[i][l]);
					v[j]=0;
				} 
			} 
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int p;
			cin>>p;
			cin>>t[p][i];
			e[i].push_back(p);
			nd[p].push_back(i);
		}
	}
	while(q--){
		memset(v,0,sizeof(v));
		ans=1e18;
		int st,ed;
		cin>>st>>ed;
		for(int i:nd[st]){
			v[i]=1;
			dfs(i,ed,w[st]+t[st][i]);
			v[i]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
