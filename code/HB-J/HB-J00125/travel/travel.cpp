#include<bits/stdc++.h>
using namespace std;
int main(){
freopen ("travel.in","r","stdin");
freopen ("travel.out","w","stdout");
string a,b;
char c,d,e,f,g,h;
cin>>a;
cin>>c>>d>>e;
cin>>b;
cin>>f>>g>>h;
if(a==b)
cout<<"1";
else cout<<"0";
if(c==f&&d==g)
    cout<<"1";
    else cout<<"0";
if(e==h+1||e==h-1)
    cout<<"1";
else cout<<"0";
if(e==h+1||e==h-1)
    cout<<"1";
else cout<<"0";
return 0;
}
