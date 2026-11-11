#include<bits/stdc++.h>
using namespace std;
char a,b,c,d;
int e=0,l=0,k=0,j=0;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);	
cin>>a>>b>>c>>d;	
if(a!=01&&a!=16){
e++;	
}	
if('b'-'d'<=3){
l++;	
}
if(c!=01&&c!=16){
k++;	
} 
if('d'-'b'<=1){
j++;	
}
cout<<e<<l<<k<<j;
return 0;	
}
