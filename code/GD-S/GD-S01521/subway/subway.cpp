#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505]={0},k[500005]={0},x,y,f[500005]={0};
int a[505][500005]={0},t[505][500005],T;
int ans[100005]={0};
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			f[a[i][j]]=i;
			T=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		
	}
	
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	int hlewintesnblplchampion
	return 0;
}

