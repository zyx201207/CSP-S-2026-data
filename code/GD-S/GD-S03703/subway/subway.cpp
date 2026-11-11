#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[50005],k[505],a[505][20005],t[505][20005],x[100005],y[100005],ans[100005],xx[505],yy[505];
long long minn;
int main(){
	freopen("subway1.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;++i)cin>>x[i]>>y[i];
	for(int i=1;i<=q;++i){
		ans[i]=w[x[i]];
		ans[i]+=w[y[i]];
		for(int j=1;j<=n;++j){
			for(int l=1;l<=k[j];++l){
				if(a[j][l]==x[i]){
					xx[j]++;
					break;
				}
				if(a[j][l]==y[i]){
					yy[j]++;
					break;
				}
			}
		}
		for(int j=1;j<=n;++j){
			if(xx[j]==1&&yy[j]==1)break;
			if(xx[j]==0)continue;
			for(int l=1;l<=n;++l){
				if(yy[l]==0)continue;
				for(int r=1;r<=min(k[j],k[l]);++r)
					if(a[j][r]==a[l][r])
						minn=min(minn,(long long)(t[j][r]+t[l][r]));
			}
		}
		ans[i]+=minn;
	}
	for(int i=1;i<=q;++i)cout<<ans[i]<<"\n";
	return 0;
} 
