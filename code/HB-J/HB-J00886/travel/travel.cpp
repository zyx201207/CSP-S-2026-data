#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool flag=0,F=0;
    if(a==c){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
        if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
            cout<<1;
            flag=1;
        }else{
            cout<<"00";
            return 0;
        }
    }else if(d[2]=='D'||d[2]=='F'){
        if(b[2]=='D'||b[2]=='F'){
            cout<<1;
            F=1;
        }else{
            cout<<"00";
            return 0;
        }
    }
    if((flag||F)&&(b[2]+1)==d[2]||d[2]+1==b[2]){
        cout<<1;
    }else cout<<0;
    return 0;
}
