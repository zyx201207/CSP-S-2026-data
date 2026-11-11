#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,l,ans,a[31][215414];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[30][i];
	for(int i=30;i>=0;i--){
		k=0;
		for(int j=1;j<=n;j++) k+=(a[i][j]>>i)%2;
		if(i==0){
			if(k>=m) ans+=(1<<i);
			break;
		}
		if(k>=m){
			ans+=(1<<i),l=0;
			for(int j=1;j<=n;j++){
				if((a[i][j]>>i)%2) a[i-1][++l]=a[i][j];
			}
			n=l;
		}
		else for(int j=1;j<=n;j++) a[i-1][j]=a[i][j];
	} 
	cout<<ans;
}
