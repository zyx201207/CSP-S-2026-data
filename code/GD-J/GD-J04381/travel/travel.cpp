#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e3+10;
const int INF=0x3f3f3f3f;
string c1,s1,c2,s2;
bool f;
int x,y;
signed main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   cin>>c1>>s1>>c2>>s2;
   if(c1==c2){
   	cout<<1;
   }else{
   	cout<<"0000";
   	return 0;
   }
   for(int i=0;i<s2.size()-1;i++){
   		    if(s1[i]!=s2[i]){
   		    	f=1;
			   	cout<<"000";
			   	break;
		}
   }
   if(!f){
   	cout<<1;
   }else{
   	return 0;
   }
   if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
   	x=1;
   }else{
   	x=2;
   }
   if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
   	y=1;
   }else{
   	y=2;
   }
   if(x==y){
   	cout<<1;
   }else{
   	cout<<"00";
   	return 0;
   }
   int a=int(s2[2]-s1[2]);
   if(abs(a)==1){
   	cout<<1;
   }else{
   	cout<<0;
   }
	return 0;
}

