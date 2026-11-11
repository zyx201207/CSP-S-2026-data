#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","s",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1>>s1>>c2>>s2;
    if(c1==c2){
        cout << "1";
    }else{
        cout <<"0";
    }
     if(c1!="01"&&c1!="16"){
        cout << "1";
    }else{
        cout <<"0";
    }
     if(s1!="C"&&s2!="D"){
            cout << "1";
        }else{
            cout << "0";
    }
    if(s1!=s2){
        cout <<"1";
    }else{
        cout <<"0";
    }
    return 0;
}
