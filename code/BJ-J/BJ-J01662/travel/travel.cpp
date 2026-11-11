#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(b[0]!=d[0]||b[1]!=d[1]){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    if(b[2]=='F'){
        if(d[2]!='D'){
            cout<<"00";
            return 0;
        }
    }
    if(b[2]=='D'){
        if(d[2]!='F'){
            cout<<"00";
            return 0;
        }
    }
    if(b[2]=='C'){
        if(d[2]=='D'||d[2]=='F'){
            cout<<"00";
            return 0;
        }
    }
    if(b[2]=='B'){
        if(d[2]=='D'||d[2]=='F'){
            cout<<"00";
            return 0;
        }
    }
    if(b[2]=='A'){
        if(d[2]=='D'||d[2]=='F'){
            cout<<"00";
            return 0;
        }
    }
    cout<<"1";
    if(b[2]=='D'||b[2]=='F'||b[2]=='B'||d[2]=='B'){
        cout<<"1";
        return 0;
    }
    cout<<"0";
    return 0;
}
