#include<bits/stdc++.h>
using namespace std;
int main(){
  // ios::sync_with_stdio(0)；
  // cin.tie(0);
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   string c1,c2,c3,c4;
   cin>>c1>>c2>>c3>>c4;
   if(c1!=c3){
	   cout<<"0000";
	   return 0;
   }
   int n=c2.size()-1,n2=c4.size()-1;
   cout<<(c1==c3)<<(c2.substr(0,2)==c4.substr(0,2));
   if((c2.substr(0,2)!=c4.substr(0,2))){
	   cout<<"00";
	   return 0;
   }else{
	   cout<<((c2[c2.size()-1]>='A'&&c2[c2.size()-1]<='C'&&c4[c4.size()-1]>='A'&&c4[c4.size()-1]<='C')||(c2[c2.size()-1]>='D'&&c2[c2.size()-1]<='F'&&c4[c4.size()-1]>='D'&&c4[c4.size()-1]<='F'));  
   }
   if(c2[n]=='A'&&c4[n2]=='B'){
	   cout<<1;
	   return 0;
   }
   if(c2[n]=='B'&&c4[n2]=='C'){
	   cout<<1;
	   return 0;
   }
   if(c2[n]=='D'&&c4[n2]=='F'){
	   cout<<1;
	   return 0;
   }
   cout<<0;
   return 0;
}
