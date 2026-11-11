#include <bits/stdc++.h> 
//#include <iostream> 
using namespace std;
typedef long long ll;
//ios::

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
 int c1=91,c2=78,ji=0,maxx=0;
 ll sb=2,bn=67,a=1,b=1,ld=0;
 cin>>a>>b;
 for (int i=1;i<=a;i++){
 	cin>>sb;
 	if(maxx<=ji){
	 maxx=ji;
	 ld=sb;}
 	while (sb!=0){
 		ji+=sb%2;
 		ji*=10;
		sb/=2;	
	 }
	ji=0;	 
	 //cout <<ji<<endl<<endl;
	 
	 
 	
 }
 

cout<<ld;

 return 0;
}
