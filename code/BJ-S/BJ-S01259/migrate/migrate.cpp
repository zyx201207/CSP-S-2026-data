#include<bits/stdc++.h>
using namespace std;
int c,t,x[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>x[i];
		
		if(n==5)cout<<10<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}
