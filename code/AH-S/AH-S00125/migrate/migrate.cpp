#include<bits/stdc++.h>
using namespace std;
int cs,t,n,m;
long long a[5145],b[5145][5145],c[5145][5145],d[5145][5145];
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>cs>>t;while(t--){
		cin>>n>>m;memset(b,0,sizeof(b));memset(c,0x3f,sizeof(c));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]-a[j]<=m){c[j][i]=1;d[j][i]=1;}
			}
		}
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=n;j++)cout<<c[i][j]<<' ';
		//	cout<<"\n";
		////}
		int as=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(c[i][j]==c[i][k]+c[k][j]&&d[i][k]&&d[k][j]&&d[i][j]){
						b[i][j]++;
					}else if((c[i][j]>c[i][k]+c[k][j])&&d[i][k]&&d[k][j]){
						if(c[i][k]+c[k][j]!=0&&d[i][k]&&d[k][j]){b[i][j]=1;
						c[i][j]=c[i][k]+c[k][j];d[i][j]=1;}
					}
				}
			}
		}for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)if(b[i][j]==2)as++;
		}cout<<as<<"\n";
	}
	return 0;
}
