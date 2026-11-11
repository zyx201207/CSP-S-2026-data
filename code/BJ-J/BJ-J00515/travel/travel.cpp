#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string i="0000";
    string c1,c2;
    string s1,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1[0]==s1[0]&&s1[1]==c1[1]){
        i[0]='1';
    }else{
        cout<<i;
        return 0;
    }
    if(c2[0]==s2[0]&&s2[1]==c2[1]){
        i[1]='1';
    }else{
        cout<<i;
        return 0;
    }
    if(c2[2]=='D'||s2[2]=='D'){
        if(c2[2]=='F'||s2[2]=='F'){
            i[2]='1';
            i[3]='1';
            cout<<i;
            return 0;
        }else{
            cout<<i;
            return 0;
        }
    }else if(c2[2]!='F'&&s2[2]!='F'){
        i[2]='1';
        if(c2[2]=='B'||s2[2]=='B'){
            i[3]='1';
            cout<<i;
            return 0;
        }
    }
    cout<<i;
    return 0;
}
