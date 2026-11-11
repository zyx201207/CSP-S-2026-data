#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){//同车厢
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if((b[1]==d[1])&&(b[0]==d[0])){//同行
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(b[2]=='D'||b[2]=='F'){//同侧
        if(d[2]=='D'||d[2]=='F'){
            cout<<11;
            return 0;
        }else{
            cout<<"00";
            return 0;
        }
    }else{
        if(d[2]=='D'||d[2]=='F'){
            cout<<"00";
            return 0;
        }else{
            cout<<1;
        }
    }
    if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')){//挨着
        cout<<0;
    }else{
        cout<<1;
    }
    return 0;
}


