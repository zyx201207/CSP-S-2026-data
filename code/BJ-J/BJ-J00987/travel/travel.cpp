#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int k;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);//02 02B 02 01A
    ios::sync_with_stdio(false);
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else{cout<<"0000";return 0;}

    for(int i=0;i<2;i++){
        if(b[i]!=d[i]) cout<<0,k=1;
    }
    if(k==0) cout<<1;

    if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')&&k==0) cout<<1;
    else cout<<0;

    if(k==0&&(b[2]=='F'&&d[2]=='D')||(b[2]=='C'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='D'&&d[2]=='F')||(b[2]=='B'&&d[2]=='C')||(b[2]=='A'&&d[2]=='B')) cout<<1;
    else cout<<0;
    return 0;
}
