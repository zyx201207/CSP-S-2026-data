#include<bits/stdc++.h>
using namespace std;
int main()
{
char b[100],d[100];
int a,c;
cin>>a>>b[100]>>c>>d[100];
if(a==c){
for(int i=1;i<=2;i++){
if(b[i]==d[i])
{
if(b[3]=='C'||'D'){
if(b[3]+d[3]%2==1){
cout<<"1111";}
else{
cout<<"1110";}
}
else{
cout<<"1100";}
}
else{
cout<<"1000";}
}
}
else{
cout<<"0000";}
return 0;
}
