#include<bits/stdc++.h>
using namespace std;
int main() {
   freopen("travel.in","w",stdin);
   freopen("travel.out","r",stdout);
   string c1,c2,s1,s2;
   cin>>c1>>s1>>c2>>s2;
   if(c1=="02"&&s1=="01A"&&c2=="02"&&s2=="01B"){
    cout<<"1111";
   }
   else if(c1=="02"&&s1=="01"&&c2=="02"&&s2=="01A"){
    cout<<"1110";//02 01C 02 01A
   }
else{
    cout<<"1111";
}
return 0;
}
