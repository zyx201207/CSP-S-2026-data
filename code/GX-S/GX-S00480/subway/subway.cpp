#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int c,n,m,d,q;
vector<pair<int,int> > dtz[N],zt[N];
int w[N],t[N][N],k[N];
long long sum=0;
void dfs(int x){
	sum+=dtz[x].second;
	for(int i=0;i<dtz[x].size();i++){
		int y=zt[dtz[x].first].size;
		for(int j=0;j<y;j++){
			if(zt[j].first!=x) dfs(zt[j].first);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]!=1) f=1;
		for(int j=1;j<=k[i];j++){
			int x,t;
			cin>>x>>t;
			dtz[x].push_back({j,t});
			zt[j].push_back({x,t});
		}
	}
	if(f==0){
		for(int i=1;i<=q;i++) cout<<0<<endl;
		return 0;
	}
	int sum=0;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		sum=0;
		sum+=w[x]+w[y];
		for(int j=1;j<=n;j++){
			if(k[i]==2&&dtz[x].size()!=0){
				dfs(x);
			} 
		}
		cout<<sum<<endl;
	}
	return 0;
}
