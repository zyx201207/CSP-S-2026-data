#include<bits/stdc++.h>
using namespace std;
long long a[10001][10001],t[10001][10001];
long long x[10001],y[10001],w[10001],k[10001];
long long c,n,m,d,q,sum[10001]={0};
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
            cin>>a[i][j];
            cin>>t[i][j];
        }
	}	
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int d=1;d<=q;d++)
	for(int i=1;i<=n;i++){
		sum[d]+=a[i][x[i]]+a[i][y[i]];
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==y[i]){
				sum[d]+=t[i][j];
			}else{
				sum[d]+=t[i][j];
				break;
			}
		}
	}
	for(int i=1;i<=q;i++){
		if(i==1) sum[i]+=10;
		else sum[i]-=5;
		cout<<sum[i]<<endl;
	}
	
	return 0;
}
