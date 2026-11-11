#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,e;
    cin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1]){
        e+="1";
        if(b[0]==d[0]&&b[1]==d[1]){
            e+="1";
            if(b[2]=='A'||b[2]=='B'||b[2]=='C'&&d[2]=='A'||d[2]=='B'||d[2]=='C'){
                e+="1";
                char p=b[2];
                char o=d[2];
                if(p-'0'+1==o-'0'){
                    e+="1";
                }
                else if(p-'0'-1==o-'0'){
                    e+="1";
                }
                else{
                    e+="0";
                }
            }
            if(b[2]=='D'||b[2]=='E'&&d[2]=='D'||d[2]=='E'){
                e+="11";
            }
            else{
                e+="00";
            }
        }
        else{
            e+="000";
        }
    }cout<<e;
    return 0;
}