#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k[505],w[500005],a[505][5005],t[505][500005],x[100005],y[100005],ans,b;
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
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			for(int z=1;z<=k[i];z++){
				if(a[j][z]<=y[i]&a[j][z]>=x[i]){
					ans+=t[j][z];
					if(a[j][z]==y[i]){
						j=n;
					}
				}
			}
		}
		ans+=w[x[i]]+w[y[i]];
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
