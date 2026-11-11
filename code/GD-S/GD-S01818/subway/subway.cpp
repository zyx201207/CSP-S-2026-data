#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
struct node{
	int lin,tim;
};
vector<node>p[maxn];
int c,n,m,d,q,a[maxn],f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e15;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x;
		while(x--){
			cin>>y>>z;
			node tmp;
			tmp.lin=i,tmp.tim=z;
			p[y].push_back(tmp);
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:p[i]){
			for(auto y:p[i]){
				f[x.lin][y.lin]=min(f[x.lin][y.lin],x.tim+y.tim);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y,res=1e15;
		cin>>x>>y;
		for(auto t1:p[x]){
			for(auto t2:p[y]){
				res=min(res,a[x]+a[y]+t1.tim+t2.tim+f[t1.lin][t2.lin]);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}

