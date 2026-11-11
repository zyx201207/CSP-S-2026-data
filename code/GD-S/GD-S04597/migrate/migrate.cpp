#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cout<<n-d+c-t<<endl;
	}
	
	return 0;
} 
