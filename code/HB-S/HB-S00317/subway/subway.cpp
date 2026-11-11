#include<bits/stdc++.h>
using namespace std;
#define ll long long

int c,n,m,d,q,st[20005][20005],w[500005],k[505],a,t,ans,x,y;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			st[a][i]=t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=1e9+7;
		for(int j=1;j<=m;j++){
			if(st[x][j]!=0&&st[y][j]!=0){
				ans=min(ans,w[x]+w[y]+st[x][j]+st[y][j]);
			}
		}
		cout<<ans<<endl;
	}/*blindly cheat score*/
	
	return 0;
}
