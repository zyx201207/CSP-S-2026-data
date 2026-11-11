#include<bits/stdc++.h>
using namespace std;
#define int long long
bool g[4];
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        g[0]=1;
    }
    if(b[0]==d[0]&&b[1]==d[1]){
        g[1]=1;
    }
    if((b[2]<='C')==(d[2]<='C')){
        g[2]=1;
    }
    if((b[2]!='A'||d[2]!='C')&&(b[2]!='C'||d[2]!='A')){
        g[3]=1;
    }
    g[1]&=g[0];
    g[2]&=g[1];
    g[3]&=g[2];
    cout<<g[0]<<g[1]<<g[2]<<g[3];
    return 0;
}
