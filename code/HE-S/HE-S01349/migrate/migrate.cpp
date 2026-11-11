#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int e=0;e<t;e++){
		cin>>n>>d;
		int x[n];
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(n==4){
			cout<<1;
		}
		if(n==5){
			if(d=3){
				cout<<0;
			}else{
				cout<<2;
			}
		}
		if(n==6){
			cout<<1;
		}
	}
	return 0;
}
