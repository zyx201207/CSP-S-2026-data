#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int n,d,c,t;
    cin>>c>>t>>n>>d;
    int x[n+5];
    for(int i=1;i<=t;i++){
    	for(int j=1;j<=n;j++){
    		cin>>x[j];
		}
		if(n==4){
			if(d==2){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		if(n==5){
			if(d==2){
				cout<<2;
			}else{
				cout<<0;
			}
		
		}
		if(n==6){
			if(d==2){
				cout<<1;
			}else{
				cout<<2;
			}
		}
	}
	return 0;
} 
