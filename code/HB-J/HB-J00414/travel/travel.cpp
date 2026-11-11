#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f="1111";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        e="1";
        if(b[0]==d[0]&&b[1]==d[1]){
            e=e+"1";
            if(b[2]=='F'||b[2]=='D'){
                    if(d[2]=='F'||d[2]=='D'){
                            e=e+"11";
                    }
            }
            if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
                if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
                    e=e+"1";
                    if(d[2]-b[2]-'0'==1||b[2]-d[2]-'0'==1) e=e+"1";
                    else e=e+"0";
                }
                else e=e+"00";
            }
        }
        else e=e+"000";
    }
    else e="0000";
    cout<<e;
    return 0;
}
