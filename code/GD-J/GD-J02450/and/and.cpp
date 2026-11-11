#include <bits/stdc++.h>
using namespace std;
int a[200005];
int f[22000][22000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		for(int i=1;i<=n;i++) f[i][1]=a[i];
		for(int i=2;i<=n;i++){ //遍历行 
			for(int j=2;j<=m;j++){ //遍历列 
				for(int k=1;k<i;k++){ //遍历之前的 
					f[i][j]=f[i][j-1];
					f[i][j]=max(f[i][j-1]&f[k][m-j+1],f[i][j]);
				}
			}
		}
		cout<<f[n][m];
	}else{
		sort(a+1,a+1+n,greater<int>());
		int cnt=a[1];
		for(int i=1;i<=m+1;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}
	return 0;
}
