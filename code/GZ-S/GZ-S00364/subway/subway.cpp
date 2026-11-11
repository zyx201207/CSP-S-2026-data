//GZ-S00364 遵义市第四中学 隆银艳
#include<bits/stdc++.h>
using namespace std;
const int M=50010;
int c,n,m,d,q;
long long tim[M];
int w[M],k[M],a[M][500],t[M][500],x[M],y[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		tim[i]=w[x[i]]+w[y[i]];
	//	cout<<"tim["<<i<<"]="<<tim[i]<<endl;
		for(int j=x[i];j<y[i];j++){
			for(int z=x[i];z<y[i];z++){
			//	cout<<"j"<<j<<" z"<<z<<"  "<<t[j][z]<<"\n";
				tim[i]+=t[j][z];
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<tim[i]<<endl;
}

