#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool check(char a,char b){
    if((a=='A' || a=='B' || a=='C') && (b=='A' || b=='B' || b=='C')){
        return true;
    }
    if((a=='D' || a=='F') && (b=='D' || b=='F')){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]+s1[1]==s2[0]+s2[1]){
            cout<<1;
            if(check(s1[2],s2[2])==true){
                cout<<1;
                if(s1[2]-1==s2[2] || s2[2]-1==s1[2]){
                    cout<<1;
                }else cout<<0;
            }else cout<<"00";

        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
