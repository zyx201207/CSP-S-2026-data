#include <bits/stdc++.h>
using namespace std;

bool check(string x,string y){
    if((x[3]>='A'&&x[3]<='C')&&(y[3]>='A'&&y[3]<='C')){
        return true;
    }
    if((x[3]>='D'&&x[3]<='E')&&(y[3]>='D'&&y[3]<='E')){
        return true;
    }
    return false;
}

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string s1,s2,c1,c2;

    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }

    if(s1[0]+s1[1]==s2[0]+s2[1]){
        cout<<"1";
    }
    else{
        cout<<"0";
    }

    if(check(s1,s2)){
        cout<<"1";
    }
    else{
        cout<<"0";
    }

    if(abs(s1[3]-s2[2])==1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }


    return 0;
}
