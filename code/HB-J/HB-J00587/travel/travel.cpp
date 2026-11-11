#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r,x;
    long long rc,xc;
    cin>>rc>>r>>xc>>x;
    cout<<(rc==xc);
    if(r[0]==x[0]&&r[1]==x[1]&&rc==xc){
        cout<<1;
        char a=r[2];
        if(x[2]<='C'&&x[2]<='C'||r[2]>='D'&&x[2]>='D'){
            cout<<1;
            if(r[2]+1==x[2]||r[2]-1==x[2])
                cout<<1;
            else
                cout<<0;
        }else
            cout<<0<<0;
    }
    else
        cout<<"000";
    return 0;
}
