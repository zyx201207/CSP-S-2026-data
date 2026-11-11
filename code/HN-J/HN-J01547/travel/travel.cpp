#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);  
	freopen("travel.out","w",stdout);
   long long n,m;
   string a,b;
   cin>>n>>a>>m>>b;
   if(n==m){
   	cout<<1;
   }else{
   	cout<<"0000";
   	return 0;
   }if(a[0]==b[0] && a[1]==b[1]){
   	cout<<1;
   }else{
   	cout<<0;
   }if((a[2]<='D') && (b[2]<='D')){
   	cout<<1;
   }else if((a[2]=='D' && b[2]=='F') || (a[2]=='F' && b[2]=='D')){
   	cout<<1;
   }if(char(a[2]+1)==b[2]){
   	cout<<1;
   }else if(char(b[2]+1)==a[2]){
   	cout<<1;
   }else{
   	cout<<0;
   }
   return 0;
} 
