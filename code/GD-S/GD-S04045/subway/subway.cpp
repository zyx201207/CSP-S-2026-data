#include<bits/stdc++.h>
using namespace std;
int ce,n,m,de,p,x,y;
long long a[1010][1010],b[1010],c[1010],d[1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ce>>n>>m>>de>>p;
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j) a[i][j]=1e12;
		}
	}
	while(n--){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>c[i]>>d[i];
			for(int j=i-1;j>=1;j--){
				a[c[i]][c[j]]=a[c[j]][c[i]]=min(a[c[i]][c[j]],d[i]+d[j]);
			}
		}		
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				a[j][k]=a[k][j]=min(a[j][k],a[i][j]+a[i][k]);
			}
		}
	}	
	while(p--){
		cin>>x>>y;
		cout<<a[x][y]+b[x]+b[y]<<endl;
	}
	return 0;
}
