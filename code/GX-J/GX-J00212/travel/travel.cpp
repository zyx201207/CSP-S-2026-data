#include<bits/stdc++.h>
using namespace std;
string x,y,a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>x>>b>>y;
    if(a==b)
        cout<<1;
    else
        cout<<0;
    if(a==b&&x[0]==y[0]&&x[1]==y[1])
        cout<<1;
    else
        cout<<0;
    if(a==b&&x[0]==y[0]&&x[1]==y[1]&&((x[2]!='D'&&x[2]!='F'&&y[2]!='D'&&y[2]!='F')||((x[2]=='D'&&y[2]=='F')||(x[2]=='F'&&y[2]=='D')))){
        cout<<1;
        if((x[2]=='A'&&y[2]=='B')||(x[2]=='B'&&y[2]=='A')||(x[2]=='C'&&y[2]=='B')||(x[2]=='B'&&y[2]=='C')||(x[2]=='D'&&y[2]=='F')||(x[2]=='F'&&y[2]=='D'))
            cout<<1;
        else
            cout<<0;
    }else
        cout<<"00";
    return 0;
}
