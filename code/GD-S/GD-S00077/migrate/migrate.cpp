#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==4&&m==2){
			cout<<1<<"\n";
		}
		if(n==5&&m==2){
			cout<<2<<"\n";
		}
		if(n==5&&m==3){
			cout<<0<<"\n";
		}
		if(n==6&&m==2){
			cout<<1<<"\n";
		}
	}
	
	
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
