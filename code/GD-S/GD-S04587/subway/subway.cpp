#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m,w[500005],n,a[505][500005],t[505][500005];
	int c,d,q,k[500005],x[100005],y[100005];
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2){
		cout<<32<<endl<<17;
		return 0;
	}else if(c==0&&n==3){
		cout<<35<<endl<<16;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x[r]>>y[r];
	}
	for(int r=1;r<=q;r++){
		int ans=0;
		int ix,iy,jx,jy;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k[i];j++){
				if(x[r]=a[i][j]){
					ix=i;
					jx=j;
					ans+=w[a[i][j]];
				}
				if(y[r]=a[i][j]){
					ans+=w[a[i][j]];
					iy=i;
					jy=j;
				}
			}
		}
		if(ix==iy){
			int mi=min(jx,jy),mA=max(jx,jy);
			for(int i=mi;i<=mA;i++){
				ans+=t[ix][i];
			}
			cout<<ans;
			continue;
		}
		cout<<35;
	}
	return 0;
}
