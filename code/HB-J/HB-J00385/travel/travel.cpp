#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a[0]==c[0] && a[1]==c[1]){
        cout<<1;
    }
    else{
        cout<<0000;
    }

    if(b[0]==d[0] && d[1]==d[1]){
        cout<<1;
    }
    else{
        cout<<000;
    }

    if(b[2]=='A' && d[2]=='B' || b[2]=='B' && d[2]=='A' || b[2]=='B' && d[2]=='C' || b[2]=='C' && d[2]=='B' || b[2]=='C' && d[2]=='A' || b[2]=='A' && d[2]=='C' || b[2]=='D' && d[2]=='F' || b[2]=='F' && d[2]=='C'){
        cout<<1;
    }
    else{
        cout<<00;
    }

    if(b[2]=='A' && d[2]=='B' || b[2]=='B' && d[2]=='A' || b[2]=='B' && d[2]=='C' || b[2]=='C' && d[2]=='B' || b[2]=='D' && d[2]=='F' || b[2]=='F' && d[2]=='C'){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
