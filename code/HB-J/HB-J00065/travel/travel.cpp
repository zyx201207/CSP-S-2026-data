#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    string row1,row2;
    char type1,type2;
    row1=s1.substr(0,2);
    type1=s1[2];
    row2=s2.substr(0,2);
    type2=s2[2];
    if(c1==c2&&row1==row2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&row1==row2&&((type1>='A'&&type1<='C'&&type2>='A'&&type2<='C')||(type1>='D'&&type1<='E'&&type2>='D'&&type2<='E'))){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&row1==row2&&((type1>='A'&&type1<='C'&&type2>='A'&&type2<='C')||(type1>='D'&&type1<='E'&&type2>='D'&&type2<='E'))&&abs(type1-type2)==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
