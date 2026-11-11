#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans=0,w[500005],t[10][500005],a[10][500005],k[10];
bool vis[10][500005],loop=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
	cin>>a[i][j]>>t[i][a[i][j]];
	vis[i][a[i][j]]=1;
}
    }
    while(q){
    	q--;
    	int x,y;
    	cin>>x>>y;ans=w[x]+w[y];
	if(n==1){cout<<ans+t[1][x]+t[1][y]<<endl;break;}
	if(n==2){
		for(int i=1;i<=k[1];i++) if(a[1][i]==x) loop=1; 
		if(loop&&!vis[1][y]){
			int p;
			for(int i=1;i<=m;i++) if(vis[1][i]&&vis[2][i]){p=i;break;}
			//cout<<p<<endl<<ans<<' '<<t[1][p]<<' '<<t[2][p]<<' ';
			cout<<ans+t[1][p]+t[2][p]+t[1][x]+t[2][y]<<endl;
		}
		if(!loop&&!vis[2][y]){
			int p;
			for(int i=1;i<=m;i++) if(vis[1][i]&&vis[2][i]){p=i;break;}
			//cout<<p<<endl<<ans<<' '<<t[1][p]<<' '<<t[2][p]<<' ';
			cout<<ans+t[1][p]+t[2][p]+t[1][x]+t[2][y]<<endl;
		}
		if(!loop&&vis[2][y]) cout<<ans+t[1][x]+t[1][y]<<endl;
		if(loop&&vis[1][y]) cout<<ans+t[1][x]+t[1][y]<<endl;
	}
    }
    return 0;
}
