#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n%d!=0){
			cout<<"0";
		}
		else{
			cout<<"1";
		}
	}
	return 0;
} 
