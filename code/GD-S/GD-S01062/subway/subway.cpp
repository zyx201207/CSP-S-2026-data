#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int NN=5e2+5;
int c,n,m,d,q,ans;
int dow[N];
int dis[NN][NN];
struct node{
	int sub,t;
};
vector<node> e[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>dow[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][i]=0;
			dis[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int did,tm;
			cin>>did>>tm;
			if(e[did].size()!=0){
				for(node oth:e[did]){
					dis[i][oth.sub]=min(oth.t+tm,dis[i][oth.sub]);
					dis[oth.sub][i]=min(oth.t+tm,dis[oth.sub][i]);
				}
			}
			e[did].push_back({i,tm});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=LONG_MAX;
		for(node has1:e[x]){
			for(node has2:e[y]){
				int sub1=has1.sub,sub2=has2.sub;
				if(sub1==sub2){
					ans=min(ans,has1.t+has2.t);
				}
				else{
					ans=min(ans,dis[sub1][sub2]+has1.t+has2.t);
				}
			}
		}
		ans+=(dow[x]+dow[y]);
		cout<<ans<<endl;
	}
}
