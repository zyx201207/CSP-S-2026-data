#include<bits/stdc++.h>
using namespace std;
long long a,t,k,plan[2][110000];
long long in[55000][510],w[550000];
vector<pair<int,int>>e[600000];
int c,n,m,d,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			e[a].push_back({i,t});
			in[i][a]=t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>plan[0][i]>>plan[1][i];
		long long gd=w[plan[0][i]]+w[plan[1][i]],ans=1e9;
		for(auto j:e[plan[0][i]]){
			if(in[j.first][plan[1][i]]!=0){
				ans=min(ans,gd+in[j.first][plan[0][i]]+in[j.first][plan[1][i]]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
