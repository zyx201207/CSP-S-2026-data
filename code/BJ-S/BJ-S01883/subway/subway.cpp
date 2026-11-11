#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x":"<<(x)<<' '
#define dbe(x) cerr<<#x":"<<(x)<<'\n'
#define eb emplace_back
#define ep emplace
#define endl '\n'
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using tp=tuple<int,int>;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vi w(m);
	for(int&v:w)cin>>v;
	vector<vector<tp>>sw(n);
	vector<vector<tp>>lst(m);
	for(int i=0;i<n;i++){
		int k;cin>>k;
		sw[i].resize(k);
		for(auto&[a,t]:sw[i]){
			cin>>a>>t;a--;
			lst[a].eb(i,t);
		}
	}
	vector<vl>dis(n,vl(n,1e18));
	for(int i=0;i<n;i++)dis[i][i]=0;
	for(int i=0;i<m;i++){
		for(auto [i1,t1]:lst[i]){
			for(auto [i2,t2]:lst[i]){
				dis[i1][i2]=min(dis[i1][i2],(ll)t1+t2);
			}
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;x--,y--;
		if(x==y){cout<<0<<endl;continue;}
		ll ans=1e18;
		for(auto [i1,t1]:lst[x]){
			for(auto [i2,t2]:lst[y]){
				ans=min(ans,w[x]+t1+dis[i1][i2]+t2+w[y]);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}