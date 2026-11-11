#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){cout<<"0000";return 0;}
    else cout<<1;
    if(b[0]==d[0] and b[1]==d[1]) cout<<1;
    else{cout<<"000";return 0;}
    if(b[2]<='C' and d[2]<='C' or b[2]>'C' and b[2]<='F' and d[2]>'C' and d[2]<='F') cout<<1;
    else{cout<<"00";return 0;}
    cout<<(b[2]-1==d[2] or b[2]+1==d[2]);
    fclode(stdin);
    fclose(stdout);
    return 0;
}
