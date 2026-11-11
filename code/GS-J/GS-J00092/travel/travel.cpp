#include <bits/stdc++.h>
using namespace std;
int main () 
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","r",stdout);
    char a,b,c,d,e,f,g,h,i,j;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
    
		if(b == g){
		   cout	<<1;
		   if(c==h && d==i){
		   	cout<<1;
		   	if (e=='A' && j=='B' || e=='A' && j=='C' || e=='B' && j=='A' || e=='B' && j=='C' || e=='C' && j=='A' || e=='C' && j=='B' || e=='D' && j=='F' || e=='F' && j=='D' ) {
			   	cout<<1;
			   	if (e=='A' && j=='C' || e=='C' && j=='A'){
				   	cout<<0;
				   }
				   else {
				   	cout<<1;
				   }
			   }else {
			   	cout<<0<<0;
			   }
		   }else{
		   	cout<<0<<0<<0;
		   }
		}
		else{
			cout<<0<<0<<0<<0;
		}
		
	return 0;
} 
