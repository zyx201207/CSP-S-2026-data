#include<bits/stdc++.h>
using namespace std;
long long a,b;
string c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool flag1=false;
    bool flag2=false;
    bool flag3=false;
    bool flag4=false;
    cin>>a>>c>>b>>d;
    if(a==b) flag1=true;
    if(c[0]==d[0]&&c[1]==d[1]) flag2=true;
    if((c[2]<='C'&&d[2]<='C')||(c[2]>'C'&&d[2]>'C')) flag3=true;
    if(abs(c[2]-d[2])==1) flag4=true;
    if(flag1) cout<<"1";
    else cout<<"0";
    if(flag1&&flag2) cout<<"1";
    else cout<<"0";
    if(flag1&&flag2&&flag3) cout<<"1";
    else cout<<"0";
    if(flag1&&flag2&&flag3&&flag4) cout<<"1";
    else cout<<"0";
    return 0;
}
