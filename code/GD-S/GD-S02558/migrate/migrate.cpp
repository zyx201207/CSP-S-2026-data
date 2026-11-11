#include<bits/stdc++.h>
using namespace std;
int c,n,t,d,a[2000006],f[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			if((a[i+1]-a[i])<=d&&(a[i+3]-a[i+1])<=d&&(a[i+2]-a[i])<=d&&(a[i+3]-a[i+2]<=d)&&d<(a[i+3]-a[i]))ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
