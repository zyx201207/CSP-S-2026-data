#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N],cc[N],h[N],f[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,j;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
		cin>>cc[i];
	}
	int jx=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int aa,tt;
			cin>>aa>>tt;
			a[aa]=i;
			if(f[aa]==1){
				j=tt+h[aa];
				jx=aa;
			}
			f[aa]=1;
			h[aa]=tt;
		
	}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(a[x]!=a[y]){
			int ans=cc[x]+cc[y]+j+h[x]+h[y];
			cout<<ans<<"\n";
		}
		else if(x==jx){
			int ans=cc[x]+cc[y]+j-h[x]+h[y];
			cout<<ans<<"\n";
		}
		else if(y==jx){
			int ans=cc[x]+cc[y]+j+h[x]-h[y];
			cout<<ans<<"\n";
		}
		else{
			int ans=cc[x]+cc[y]+h[x]+h[y];
			cout<<ans<<"\n";
		}
	}
    return 0;
}
