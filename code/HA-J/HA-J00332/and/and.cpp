#include<bits/stdc++.h>
using namespace std;
int f[20005][20005],l[200005];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=2000 && m<=2000){
		for(int i=1;i<=n;i++){
			cin>>l[i];
		}
		f[0][0]=l[1];
		for(int i=1;i<=n;i++){
			f[i][0]=l[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=max(f[i-1][j],f[i-1][j-1]&l[i]);
				cout<<f[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<f[n][m];
	}
	else cout<<0;
	return 0;
}
