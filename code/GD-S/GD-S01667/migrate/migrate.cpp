#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int b[N];
int main(){
	freopen("migrate.cpp","r",stdin);
	freopen("migrate.cpp","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		int dc=b[2]-b[1];
		if(d==2*dc){
			cout<<n-3<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
} 
