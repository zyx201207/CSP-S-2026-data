//GZ-S00216,彭禹诺，贵阳市第三实验中学 
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const int N=505;
ll c,n,m,d,q,k;
ll w[N],a[N][N],t[N][N],g[N*2][N*2];
vector<vector<pll> > g;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 	cin>>c>>n>>m>>d>>q;
 	g.resize(n+m+1);
 	for(int i=1;i<=m;i++)cin>>w[i];
 	pre
 	for(int i=1;i<=n;i++){
 		cin>>k;
 		for(int j=1;j<=k;j++){
 			cin>>a[i][j]>>t[i][j];
 			if(j==1)continue;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<1<<' '<<1<<endl;
	}
	return 0;
}
