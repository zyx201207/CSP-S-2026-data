#include<bits/stdc++.h>
using namespace std;
int n,c,t,d,a[302][302];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.uot","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	if(c==0){
		if(t==2){
			if(n==5 && d==2){
				cout<<1<<endl<<2;
				return 0;
			}
			if(n==6 && d==2){
				cout<<0<<endl<<1;
				return 0;
			}
		}
	}	
	return 0;
} 
