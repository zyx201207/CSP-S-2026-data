#include<bits/stdc++.h>
using namespace std;
void f(string m,string n){
char sa,sb;
sa=m[2];
sb=n[2];
if((((sa=='A' || sa=='B') || sa=='C') && ((sb=='A' || sb=='B') || sb=='C'))||((sa=='D' || sa=='F') && (sb=='D' || sb=='F'))){
cout<<"1";
}
else{
cout<<"0";
}
int na,nb;
na=int(sa)-64;
nb=int(sb)-64;
if(abs(na-nb)==1 && na+nb!=7){
cout<<"1";
}
else{
cout<<"0";
}
}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
string a,b,c,d;
cin>>a>>b>>c>>d;
if(a==c){
cout<<"1";
if(b[1]==d[1]){
cout<<"1";
f(b,d);
}
else{
cout<<"000";
}
}
else{
cout<<"0000";
}
return 0;
}
