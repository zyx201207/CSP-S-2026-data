#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,v,d;
    cin >> c >> s >> v >> d;
    if(c==v){
        cout << "1";
    }
    else{
        cout << "0" << "0" << "0" << "0";
        return 0;
    }



    if(s[0]==d[0] && s[1]==d[1]){
        cout << "1";
    }
    else{
        cout << "0" << "0" << "0";
         return 0;
    }



    if((s[2]=='C' && d[2]=='D') || (s[2]=='D' && d[2]=='C')){
        cout << "0" << "0";
        return 0;

    }

    else if(abs(s[2]-d[2])<=2 ){
        cout << 1;

    }
    else{
        cout << "0";
    }


    if((s[2]=='D' && d[2]=='F') || (s[2]=='F' && d[2]=='D')){
        cout << "1";
    }
    else if(abs(s[2]-d[2])==1 ){
        cout << "1";
    }
    else{
        cout << "0";
    }



    return 0;
}

