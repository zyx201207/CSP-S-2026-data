#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],num,f[2][N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
//	num=a[1];
//	for(int i=2;i<=m;i++) num=num&a[i];
//	cout<<num<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(j-1>0) f[1][j]=max(f[0][j],f[0][j-1]&a[i]);
			else f[1][j]=a[i];
		}
		for(int j=0;j<=m;j++) f[0][j]=f[1][j];
	}
	cout<<f[1][m];
	return 0;
}

