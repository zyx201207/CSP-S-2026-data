#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int f,g;

    if(c1==c2){
        cout<<"1";

    if(s1[0] == s2[0] && s1[1] == s2[1]){
        cout<<"1";
        }

        int b = s1[3],q = s2[3];
        if(b=='A'||b=='B'||b=='C'){
            f = 1;
        }
        if(q=='A'||q=='B'||q=='C'){
            g = 1;
        }
        else if(b=='C'||b=='D'){
            f = 1;
        }
        else if(q=='C'||q=='D'){
            g = 1;
        }
        if(f==1&&g==1){
            cout<<"1";
        }


    if(s1[3]-s2[3] == 1||s1[3]-s2[3]==-1){
        if((s1[3]=='C'&&s2[3]=='D')||(s1[3] == 'D'&&s2[3]=='C')){
            cout<<"0";
        }
        else{
            cout<<"1";
        }}}
    else{
        cout<<"0000";
    }

return 0;
}