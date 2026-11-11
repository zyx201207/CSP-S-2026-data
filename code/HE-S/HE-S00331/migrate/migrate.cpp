#include<bits/stdc++.h>
using namespace std;

int x[100000];


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1; i<=t; i++){
		cin>>n>>d;
		for(int j=1; j<=n; j++){
			cin>>x[j];
			if(x[j]-x[j+1]<=d){
				cout<<d<<endl;
			}else{
				cout<<t-c;
			}
		}	
		
	}
	
	
	
return 0;	
}
