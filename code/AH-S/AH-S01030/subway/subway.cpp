#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505];
long long w[500010],a[505][20010],t[505][20010],x[100010],y[100010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&a[i][j]);
			scanf("%lld",&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld",&x[i]);
		scanf("%lld",&y[i]);
		cout<<w[x[i]]+w[y[i]]+n+m;
	}
    return 0;
}
