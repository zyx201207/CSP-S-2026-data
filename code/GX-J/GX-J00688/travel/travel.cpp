#include <bits/stdc++.h>
using namespace std;
int a;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n,x,y,z;
    cin>>n>>x>>y>>z;
    if(n!=y){
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    return 0;
    }
    else{
        cout<<1;
        if(x[0]==z[0]&&x[1]==z[1]){
            cout<<1;
            a=1;
        }
        else
        cout<<000;
        if(a&&(x[2]<'D'&&z[2]<'D')){
            cout<<1;
            a=2;
        }else if(a&&(x[2]<'D'&&z[2]>='D')||a&&(x[2]>='D'&&z[2]<'D'))
        cout<<00;
        else if(a&&(x[2]>='D'&&z[2]>='D'))
            cout<<11;
        if(a==2&&(x[2]=='A'&&z[2]=='B')||a==2&&(x[2]=='B'&&z[2]=='C'))
            cout<<1;
        else if(a==2&&(x[2]=='B'&&z[2]=='A')||a==2&&(x[2]=='C'&&z[2]=='B'))
            cout<<1;
        else cout<<0;
    }
    return 0;
}

