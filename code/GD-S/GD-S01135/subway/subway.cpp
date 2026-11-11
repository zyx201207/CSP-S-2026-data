#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+10;
long long c,n,m,d,q;
long long w[maxn],x[maxn],y[maxn],cnt[maxn];
long long a[505][505],t[505][505];
long long k;
long long mi[maxn]={100000086},mii[maxn]={100000086};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			if(j%2==1){
				cin>>a[i][j/2+1];
			}
			else{
				cin>>t[i][j/2];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cnt[i]=w[x[i]]+w[y[i]];
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=q;j++){
				if(a[l][j]==x[i]){
					mi[l]=min(mi[l],a[l][t])
				}
				if(a[l][j]==y[i]){
					mii[l]=min(mi[l],a[l][t]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cnt[i]+=mi[i]+mii[i],
		cout<<cnt[i]<<endl;
	}
	
	return 0;
}
