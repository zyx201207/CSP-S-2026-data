#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int read(){
	int t;
	scanf("%d",&t);
	return t;
} 
int n,m;
int a[maxn];
int f[maxn][maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		f[i][1]=max(a[i],f[i-1][1]);
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
		}
		ans=max(ans,f[i][m]);
	}
	cout<<ans;
	return 0;
}
