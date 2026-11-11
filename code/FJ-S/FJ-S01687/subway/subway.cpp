#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
int c,n,m,d,q;
int w[N],a[N][N],t[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=0;
		for(int i=x;i<=y;i++){
			ans+=t[i][x]+w[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
