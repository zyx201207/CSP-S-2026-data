#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		if (a[2]-a[1]>=2*m && a[2]-a[1]<3*m)cout<<n-3;
		else cout<<0;
		cout<<endl;
	}
}
