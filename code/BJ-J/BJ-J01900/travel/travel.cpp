#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string s;
    if(a==c){
    }else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0] and b[1]==d[1]){
    }else{
        cout<<"1000";
        return 0;
    }
    int x=0;
    int y=0;
    if(b[2]=='A' or b[2]=='B' or b[2]=='C'){
        x=1;
    }else{
        x=0;
    }
    if(d[2]=='A' or d[2]=='B' or d[2]=='C'){
        y=1;
    }else{
        y=0;
    }
    if(x==y){
    }else{
        cout<<"1100";
        return 0;
    }

    if(b[2]=='A' and d[2]=='B' or b[2]=='B' and d[2]=='A' or b[2]=='B' and d[2]=='C' or b[2]=='C' and d[2]=='B' or b[2]=='D' and d[2]=='F' or b[2]=='F' and d[2]=='D'){
    }else{
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
