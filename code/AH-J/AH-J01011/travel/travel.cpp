#include <bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","r",stdout);
cin>>c1>>c2>>s1>>s2;
if(c1==c2){
    cout<<1;
}
else{
    cout<<"0000";
    return 0;
}
s1/=10;
s2/=10;
if(s1==s2)
{
    cout<<1;
}
else{
    cout<<"000";
    return 0;
}
return 0;
}
