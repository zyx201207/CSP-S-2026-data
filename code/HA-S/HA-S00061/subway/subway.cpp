#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
struct pos{
	int id,tim;
};
vector<pos> v[500005];
int w[500005];
int f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			v[x].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		for(auto it:v[i]){
			for(auto iit:v[i]){
				if(it.id!=iit.id)f[it.id][iit.id]=min(f[it.id][iit.id],it.tim+iit.tim);
				else f[it.id][it.id]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int res=0x3f3f3f3f3f3f3f3f;
		for(auto it:v[x]){
			for(auto iit:v[y]){
				res=min(res,f[it.id][iit.id]+it.tim+iit.tim);
			}
		}
		cout<<res+w[x]+w[y]<<endl;
	}
	return 0;
}
