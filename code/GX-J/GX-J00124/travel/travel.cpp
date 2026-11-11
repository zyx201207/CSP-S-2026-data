#include<bits/stdc++.h>
using namespace std;

string s[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(short i=0;i<4;++i){
        cin>>s[i];
    }
    if(s[0]==s[2]) cout << 1;
    else{
            cout << 0 << 0 << 0 << 0;
            return 0;
    }

    if(s[1][0]+s[1][1]==s[3][0]+s[3][1]) cout << 1;
    else {
        cout << 0 << 0 << 0;
        return 0;
    }
    char ms3=s[1][2];
    char ms4=s[3][2];
    if((ms3>='A'&&ms3<='C'&&ms4>='A'&&ms4<='C') ||
       (ms3>='D'&&ms3<='F'&&ms4>='D'&&ms4<='F')) cout << 1;
    else {
        cout << 0 << 0;
        return 0;
    }
    if(ms3-ms4==1 || ms3-ms4==-1) cout << 1;
    else {
        cout << 0;
    }
    return 0;
}
