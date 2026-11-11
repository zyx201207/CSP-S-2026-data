#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(b[0]==d[0] and b[1]==d[1]){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;

    }
    if(b[2]=='F' and d[2]=='D' or b[2]=='D' and d[2]=='F' or b[2]=='A' and d[2]=='B' or b[2]=='B' and d[2]=='A' or b[2]=='A' and d[2]=='C' or b[2]=='C' and d[2]=='A' or b[2]=='B' and d[2]=='C' or b[2]=='C' and d[2]=='B'){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        return 0;
    }
    if(b[2]-d[2]==1 or d[2]-b[2]==1){
        if(b[2]=='C' and d[2]=='D' or b[2]!='D' and d[2]!='C'){
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
