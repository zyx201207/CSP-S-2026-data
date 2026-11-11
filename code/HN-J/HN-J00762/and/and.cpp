#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,ans,a[200006],f[200006][35],b[200006];
void check(int x){
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		int o=1;
		for(int j=1;j<=x;j++){
			b[i]+=f[i][j]*o;
			o*=2;
		}
	}
	sort(b+1,b+1+n);
	int g=b[n];
	for(int i=n-1;i>=n-m+1;i--){
		g=g&b[i];
	}
	ans=max(ans,g);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int d=a[i],cnt=1;
		while(d!=0){
			f[i][cnt]=d%2;
			d/=2;
			cnt++;
		}
	}
	for(int i=1;i<=30;i++){
		check(i);
	}
	cout<<ans;
	return 0;
}
