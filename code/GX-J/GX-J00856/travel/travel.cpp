#include <bits/stdc++.h>
using namespace std;
int main(){
    //fireopen("travel.in"and"r",stdin)
    //fireopen("travel.out"and"w",stdout)
    char c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1==s2){
            cout<<"11";
        }
        else{
            cout<<"00";
        }}
    if(c1!=c2){
        cout<<"0000";}
    return 0;
}

