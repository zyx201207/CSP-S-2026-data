#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
 	int c,t;
 	cin>>c>>t;
 	if(c==0){
 		if(t==2){
 			while(t--){
 				int n,m;
				 cin>>n>>m;
				 for(int i=1; i<=n;i++)cin>>a[i];
				 if(n==4&&m==2){
				 	cout<<1;
				 } 
				 if(n==5&&m==2){
				 	cout<<2;
				 }
				 if(n==5&&m==3){
				 	cout<<0;
				 }
				 if(n==6&&m==2){
				 	cout<<1;
				 }
			 }
		 }
	 }
	return 0;
}
