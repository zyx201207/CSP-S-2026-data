#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],t[505][500005],cnt,ans,a[2],vis[500005],f[15][15];
vector<int> g[500005];//每个站通向的站 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		cnt=0;
		for(int j=1;j<=k*2+1;j++){
			cnt++;
			cin>>a[1]>>t[i][cnt];
			if(cnt>=2) g[a[1]].push_back(a[0]);
			a[0]=a[1];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<'\n';
	}
	return 0;
}
