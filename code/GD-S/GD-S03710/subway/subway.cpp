#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],x,y;
int f[505][505],sz[505],tf;
vector<int>p[505];
struct node{
	int p1,p2;
};
vector<node>t[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	f[i][j]=f[j][i]=1e18;
	for(int i=1;i<=n;i++){
		cin>>sz[i];
		for(int j=1;j<=sz[i];j++){
			int fs;
			cin>>fs>>tf;
			for(node s:t[fs]){
				int g=s.p1,e=s.p2;
				f[i][g]=f[g][i]=min(f[i][g],tf+e);
			}
			t[fs].push_back({i,tf});
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
	f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		cin>>x>>y;
		int ans=1e18;
		for(node i:t[x]) for(node j:t[y]){
			int ko=f[i.p1][j.p1]+w[x]+w[y]+i.p2+j.p2;
			ans=min(ans,ko);
		}
		cout<<ans<<"\n";
	}
}
