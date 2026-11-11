#include<bits/stdc++.h>
using namespace std;
int jinzhi(int x){
	if(x==1){
		return 1;
	}
	if(x==0){
		return 0;
	}
	int iop;
	if(x%2==0){
		iop=jinzhi(x/2);
		return 0;
	}else{
		iop=jinzhi(x/2);
		return 1;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> k;
		a[i]=jinzhi(k);
	}
	int b[n][1089000000];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			while(a[i]>1){
				b[i][j]=a[i]%10;
				a[i]/=10;
			}
		}
	}
	int ans[1089000000]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(b[i][j]==b[i+k][j]&&b[i+k/2][j]==b[i][j]){
					ans[j]=b[i][j];
				}
			}
		}
	}
	for(int i=1089000000;i>0;i--){
		cout << ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}