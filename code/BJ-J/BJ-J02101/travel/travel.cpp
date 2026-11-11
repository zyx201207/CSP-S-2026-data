#include<bits/stdc++.h>
using namespace std;
const int e[5]{0,0,0,1,1};
int main(){
 freopen("travel2.in","r",stdin);
 freopen("travel2.out","w",stdout);
 string a,b,c,d;
 cin>>a>>b>>c>>d;
 if(a!=c){
    cout<<"0000";
 }else if(b[0]!=d[0]||b[1]!=d[1]){
     cout<<"1000";
 }else if(e[b[2]-'A']!=e[d[2]-'A']){
     cout<<"1100";
 }else if(abs(b[2]-d[2])==1){
     cout<<"1111";
 }else{
 cout<<"1110";}
 return 0;
}
//求acak
