#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,x,y,w[500005],k[505],a[505][20005],t[505][20005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int ans=1000000000000000000;
		for(int j=1;j<=n;j++){
			bool f1=0,f2=0;
			int t1,t2;
			for(int e=1;e<=d[j];e++){
				if(a[j][e]==x){
					f1=1;
					t1=t[j][e];
				}
				if(a[j][e]==y){
					f2=1;
					t2=t[j][e];
				}
			}
			if(f1 && f2) ans=min(ans,t1+t2+w[x]+w[y]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
