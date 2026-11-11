#include<bits/stdc++.h> 
using namespace std;
int n;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
   for(int i=0;i<n;i++){
   	int j;
   	cin>>j;	
	   char b;
   		cin>>b;
   	for(int k=0;k<j;k++){
   	a+=b;
	   }
   }
   int h=0,j;
   for(int i=0;i<a.size();i++){
   	  j=a.size()-1;
		  
   	  	if(a[i]!=a[j]){
   	  		a[j]=a[i];
   	  		h++;
			 
		 }
		 j--;
   }
   cout<<h;
   return 0;
}
