#ifndef TRAVEL_CPP_INCLUDED
#define TRAVEL_CPP_INCLUDED



#endif // TRAVEL_CPP_INCLUDED
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a=0;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        a+=1000;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
            a+=100;
        if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')
            a+=10;
            if(s1[2]==s2[1]-1||s2[2]==s1[2]-1)
            a+=1;
        cout<<a;
    }
    else cout<<"0000";

    return 0;
}
