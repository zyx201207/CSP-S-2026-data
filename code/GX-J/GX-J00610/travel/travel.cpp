#include<bits/stdc++.h>
using namespace std;
int n,m;
string x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>x>>m>>y;
    bool f=1;
    if (n==m)cout<<1;
    else {
        cout<<0;
        f=0;
    }if(x[0]==y[0]&&x[1]==y[1]&&f)cout<<1;
    else {
        cout<<0;
        f=0;
    }
    if (((x[2]<='C' && y[2]<='C') ||(x[2]>='D' && y[2]>='D'))&&f)cout<<1;
    else {
        cout<<0;
        f=0;
    }
    if ((abs(x[2]-y[2])==1)&&f){
            cout<<1;
    }
    else cout<<0;

    return 0;
}
