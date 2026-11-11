#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int l=1,r=4;
		int ans=0;
		while(l<=r&&r<=n){
			if(a[l]+m>=a[l+1]&&a[l]+m>=a[r-1]&&a[r-1]+m>=a[r]&&a[l]+m<a[r]){
				ans++;
			}
			l++;
			r++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
