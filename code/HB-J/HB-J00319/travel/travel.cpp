#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
bool out[MAXN];
bool in[MAXN];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b,c,d,e;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<"1";else cout<<"0";
    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<"1";
    }
    else cout<<"0";
    if(b[2]<='C'&&d[2]<='C'){
        cout<<"1";
    }
    else if(d[2]>'C'&&b[2]>'C'){
        cout<<"1";
    }
    else cout<<"0";
    if(b[2]==d[2]+1||b[2]==d[2]-1){
        cout<<"1";
    }
    else cout<<"0";

}
