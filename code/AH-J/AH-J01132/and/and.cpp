#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	vector<int>a(n+1);
	int f[n+1][m+1]={0};
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		f[i][1]=a[i];
		for(j=1;j<=m;j++){
			if(i+j<=n)
			f[i+j][j]=max(f[i+j][j-1],f[i][j-1]&a[i+j]);
		}
	}
	cout<<max(f[n][m],a[n]);
	return 0;
}
