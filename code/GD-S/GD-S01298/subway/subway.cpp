#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,w[500005],zong[5005][5005],a[5005][5005],t[5005][5005];
int f(int x,int y,int sum){
	for(int i=1;i<=k;i++){
		zong[x][sum++]=a[y][i];
	}
	return sum;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		int sum=1;
		for(int j=1;j<=n;j++){
			for(int o=1;o<=k;o++){
				if(i==a[j][o]){
					sum=f(i,j,sum);
				}
			}
		}
	}
	/*for(int i=1;i<=m;i++){
		cout<<i<<" ";
		for(int j=1;j<=n*k;j++){
			cout<<zong[i][j]<<" ";
		}
		cout<<endl;
	}*/
	/*for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
