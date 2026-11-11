#include<bits/stdc++.h>
using namespace std;
long long b[505],x[500005],y[500005][25],mi,z,v,c,n,m,d,be,en,q,w[500005],k[500005],a[505][50005],t[505][50005];
long long cmp(long long x1,long long y1){
	for(int i=1;i<=m;i++){
		x[i]=0;
	}
	for(int i=1;i<=n;i++){
		b[i]=0;
	}
	x[x1]=w[x1];
	mi=-1;
	while(x[y1]==0){
		mi=-1;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=y[i][0];j++){
				if(x[i]!=0&&(t[y[i][j]][i]+x[i]<mi||mi==-1)&&b[y[i][j]]==0){
					mi=t[y[i][j]][i]+x[i];
					v=y[i][j];
					z=i;
				}
			}
		}
		b[v]=1;
		for(int i=1;i<=k[v];i++){
			x[a[v][i]]=x[z]+mi+t[v][a[v][i]];
		}
	}
	return x[y1]+w[y1];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			y[a[i][j]][0]++;
			y[a[i][j]][y[a[i][j]][0]]=i;
		}
	}
	while(q--){
		cin>>be>>en;
		cout<<cmp(be,en)<<endl;
	}
	return 0; 
}
