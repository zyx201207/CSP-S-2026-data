#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,m,ans;
long long a[N],f[N][N],mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx<<"\n";
		return 0;
	}
	ans=a[1];
	for(int i=2;i<=n;i++)ans&=a[i];
	if(m==n){
		cout<<ans<<"\n";
		return 0;
}
	f[1][1]=a[1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=max(f[i-1][j-1]&a[i],f[i][j-1]);
		}
	}
	cout<<f[n][m]<<"\n";
	return 0;
}
