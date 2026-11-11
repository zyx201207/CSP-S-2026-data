#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r,r2,x,x2;
    cin>>r>>r2>>x>>x2;
    if(r==x){
        cout<<1;
        if(r2[0]==x2[0]&&r2[1]==x2[1]){
            cout<<1;
            if((r2[2]<='C'&&x2[2]<='C')||(r2[2]>'C'&&x2[2]>'C')){
                cout<<1;
                if(abs(r2[2]-x2[2])==1)cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
