#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
string r,cr,x,cx;
cin>>r>>cr>>x>>cx;
if(r==x){
cout<<"1";
if(cr[0]==cx[0]&&cr[1]==cx[1]){
cout<<"1";
if((cr[2]-'A'<=2&&cx[2]-'A'<=2)||(cr[2]-'A'>2&&cx[2]-'A'>2)){
cout<<"1";
if(((cr[2]-'A')-(cx[2]-'A')==1||(cr[2]-'A')-(cx[2]-'A')==-1)||(cr[2]-'A'==3||cx[2]-'A'==3)){
cout<<"1";
}else{
cout<<"0";
}
}else{
cout<<"00";
}
}else{
cout<<"000";
}
}else{
cout<<"0000";
}
return 0;
}
