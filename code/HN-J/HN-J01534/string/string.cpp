#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000],b[1000],c[1000],s=0;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	 for(int i=1;i<=a.size();i++){
	 	cin>>a[i];
	      	for(int j=1;j<=b.size();j++){
		 	cin>>b[j];
		 	for(int h=1;h<=c.size();h++){
		  		cin>>c[h];
				int x=a[i]+b[j]+c[h];	
		  		if(x==67){
		 			cout<<1; 
		 		}
			}
		} 
	} 
	 
	return 0;
}            
