#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1[2],s1[3],c2[2],s2[3];

    if(c1==c2){
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    if(c1==c2&&s1[0,1]==s2[0,1){
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    if(c1==c2&&s1[0,1]==s2[0,1]({
        if(s1[2]>='A'&&s1[2]<='C'){
            if(s2[2]>='A'&&s2[2]<='C'){
                cout<<'1';
            }
            else{
                cout<<'0';
            }
        }
        if(s1[2]>='D'&&s1[2]<='E'){
            if(s2[2]>='D'&&s2[2]<='E'){
                cout<<'1';
            }
            else{
                cout<<'0';
            }
        }
    }
    if(c1==c2&&s1[0,1]==s2[0,1]){
        if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
            cout>>'1';
        }
        else{cout<<'0';}}
    return 0;
}
