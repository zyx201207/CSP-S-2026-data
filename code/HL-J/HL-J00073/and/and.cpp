#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m;
int a[N];
int maxx=-2147483647;
int f[N][N]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		f[i][1]=maxx;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			f[i][j]=max(f[i-1][j],(f[i-1][j-1]&a[i]));
		}
	}
	cout<<f[n][m]<<'\n';
	return 0;
}