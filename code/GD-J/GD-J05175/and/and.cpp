#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,m;
long long a[N],f[N][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		f[i-1][0]=a[i];
	}
	f[1][1]=a[1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m&&j<=i;j++){
			f[i][j]=max(f[i-1][j],(f[i-1][j-1]&a[i]));
			//cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<f[i-1][j]<<" "<<(f[i-1][j-1]&a[i])<<endl;
		}
	}
	cout<<f[n][m];
	return 0;
}
/*
5 3
31 3 1 15 7

*/
