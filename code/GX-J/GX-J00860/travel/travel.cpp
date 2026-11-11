#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b;
int c[3],d[3];

cin>>a>>b;
 for(int i=0;i<3;i++){
 cin>>c[i];
 }
 for(int i=0;i<3;i++){
 cin>>c[i];
}
 if(a==b){cout<<"1";
 for(int i=0;i<2;i++){
 if(c[i]==d[i]) cout<<"1";
 }
 if(c[3]=='A' or c[3]=='B' or c[3]=='C'){
 if(c[3]+1==d[3] or c[3]-1==d[3]) cout<<"1"; }
 }
 else cout<<"0000";
return 0;
}
