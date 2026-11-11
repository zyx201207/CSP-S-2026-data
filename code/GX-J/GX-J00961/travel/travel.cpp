#include <bits/stdc++.h>

#define c(x) cout<<x<<endl
#define inf 0x3f3f3f3f

using namespace std;

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string x,y;
    cin>>a>>x>>b>>y;
    if(a==b) cout<<1;
    else cout<<0;
    if(a==b&&x[0]==y[0]&&x[1]==y[1])
        cout<<1;
    else cout<<0;
    if(a==b&&x[0]==y[0]&&x[1]==y[1]&&
       (x[2]<='C'&&y[2]<='C')||(x[2]>'C'&&y[2]>'C')
       )
       cout<<1;
    else cout<<0;
    if(a==b&&x[0]==y[0]&&x[1]==y[1]&&
       ((x[2]<='C'&&y[2]<='C')||(x[2]>'C'&&y[2]>'C'))&&
       abs(x[2]-y[2])==1
       )
       cout<<1;
    else cout<<0;
    return 0;
}
