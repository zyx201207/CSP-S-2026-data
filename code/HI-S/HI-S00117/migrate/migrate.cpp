#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x,y;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if(d<2*(a[2]-a[1])){
			cout<<"0\n";
		}
		else if(d<=n/2)cout<<n-3<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}
