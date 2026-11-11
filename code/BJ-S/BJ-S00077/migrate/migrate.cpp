#include<bits/stdc++.h>
using namespace std;
int t;
int a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		int lft=a[2]-a[1];
		int ge=m/lft;
		int need=2*ge-1;
		int ans=n-need;
		if(ans<0){
			cout<<0<<endl;
		}
		else cout<<ans<<endl;
	}
	
	return 0;
}
