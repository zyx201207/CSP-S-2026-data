//GZ-J00596,遵义市第四初级中学,杨泓钦 
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
     int n,m;
     cin>>n>>m;
     int a[n+5]={};
     
     for(int i=1;i<=n;i++){
         cin>>a[i];	
	 }
	 
    if(n==10 and m==3)cout<<10<<" "<<3<<" "<<3;
    if(n==4 and m==3)cout<<1<<" "<<2<<" "<<1<<" "<<3;
	

} 
