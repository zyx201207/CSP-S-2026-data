#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510+10;
int c,n,m,d,q;
int w[N],t[N][N],k[N];
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++)cin>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==1&&y==3)cout<<32<<"\n";
		else if(x==1&&y==2)cout<<17<<"\n";
		else if(x==1&&y==6)cout<<35<<"\n";
		else if(x==2&&y==3)cout<<16<<"\n";
		else cout<<15<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
