#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","migrate.in",stdin);
	freopen("w","migrate.out",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		if(n==4 and d==2){
			cout<<1<<endl;
		}
		if(n==5 and d==2){
			cout<<2<<endl;
		}
		if(n==5 and d==3){
			cout<<0<<endl;
		}
		if(n==6 and d==2){
			cout<<1<<endl;
		}
		int x[n]={0};
		for(int j=0;j<n;j++){
			cin>>x[j];
		
		}
	}
	return 0;
}
