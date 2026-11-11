#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000001];
int f[2001][2001];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[1][i]=a[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=f[i-1][j]&f[i-1][j-1];
		}
	}
	int ma=INT_MIN;
	for(int i=1;i<=n;i++){
		ma=max(ma,f[m][i]);
	}
	cout<<ma;
	return 0;
} 
