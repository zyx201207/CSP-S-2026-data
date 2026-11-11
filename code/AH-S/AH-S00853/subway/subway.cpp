#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,ans;
int w[500005],k[500005],a[500][500005],t[500][500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
		int k[i];
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0;
		if(n==1||d||1){
			for(int j=1;j<=k[1];j++){
				if(a[1][j]==x) ans+=w[x]+t[1][j];
				if(a[1][j]==y) ans+=w[y]+t[1][j];
			}
		}
		cout<<ans<<"\n";
	}
    return 0;
}
