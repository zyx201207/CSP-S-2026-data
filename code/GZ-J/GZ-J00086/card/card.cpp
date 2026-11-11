//GZ-00086 李凤涛 六盘水市第十二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500020],x[500020][500020],sum[300050];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			x[i][j]=a[i];
			if(j>=2){
				for(int k=1;k<j;k++){
					if(x[i][j]==x[i][j-k]){
					x[i][j]=0;
					sum[a[i]]++;
					break;
				    }
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
