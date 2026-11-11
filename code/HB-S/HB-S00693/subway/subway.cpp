#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=500005;
int c,n,m,d,q,w[M],a[M][505],t[M][505],k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(n==1){
			cout<<w[x]+w[y];
		}
		if(n==2){
			int ans=0x3f3f3f3f;
			for(int j=1;j<=n;j++){
				for(int j1=1;j1<=k[1];j1++){
					for(int p=1;p<=n;p++){
						for(int p1=1;p1<=k[2];p++){
							if(a[j][j1]==a[p][p1]&&a[j][j1]!=0){
								ans=min(ans,t[j][j1]+t[p][p1]);
							}
						}							
					}				
				}
			}
			ans+=(w[x]+w[y]);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
