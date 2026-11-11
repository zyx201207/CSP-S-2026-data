#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string a,b,c,d;
bool f,e,g;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        e=1;
    }else    cout<<0;
    if(!e)  cout<<0;
    else if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            f=1;
    }else   cout<<0;
    if(!e||!f)  cout<<0;
    else if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))){
        cout<<1;
        g=1;
    }else    cout<<0;
    if(!e||!f||!g)  cout<<0;
    else if((b[2]=='D'||b[2]=='F')||((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&d[2]=='B')))  cout<<1;
    else    cout<<0;
    return 0;
}
