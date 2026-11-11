#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	int c,t,n,d,a;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a;
		}
		if(n%d>=1){
			cout<<((n/d)*(n/d-1))/2;
		}
	}
	return 0;
}
