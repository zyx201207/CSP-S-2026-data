#include <bits/stdc++.h>
using namespace std;

char c1[2],s1[3],c2[2],s2[3],out[3];
int main(){
    freopen("travel.in","r",stdin);
    out="0000";
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<out;
    }
    else{
        out[0]='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
                out[1]='1';
            if((s1[2]-'A'<3&&s1[2]-'A'<3)||(s1[2]-'A'>=3&&s1[2]-'A'>=3)){
                out[2]='1';
                if(s1[2]-'A'>=3) out[3]='1';
                if(s1[2]=='B'||s2[2]=='B') out[3]='1';
            }
        }
    }
    freopen("travel.out","w",stdout);
    cout<<out;
    return 0;
}
