#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c) cout<<"0000";
    else{
        cout<<1;
        if(b[0]!=d[0]||b[1]!=d[1]) cout<<"000";
        else{
            cout<<1;
            int x=(int)(b[2]+d[2]);
            if(x=='A'+'B'||x=='A'+'C'||x=='C'+'B'||x=='D'+'F'){
                cout<<1;
                if(x!='C'+'D'&&x!='A'+'C') cout<<1;
                else cout<<0;
            }else cout<<"00";
        }
    }
    return 0;
}
