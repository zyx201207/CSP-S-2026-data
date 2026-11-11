#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005,M=30;
long long n,a[N],l=0,r=0,sum=0,ai;
long long f[N][N],m,d[N]; 
signed main(){
	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		f[i][1]=a[i];
	} //f[0]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=max(f[i][j],f[i-1][j-1]&a[i]);
			f[i][j]=max(f[i-1][j],f[i][j]);
		}
	} 
//	cout<<f[1][1];
	int maxx=0;
	for(int i=m;i<=n;i++){
		maxx=max(maxx,f[i][m]);
	} cout<<maxx;
	return 0;
} 
