#include<bits/stdc++.h>
using namespace std;
#define int long long
int get(string a){
    return (a[0]-'0')*10+(a[1]-'0');
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        int c1=get(b),c2=get(d);
        if(c1==c2){
            cout<<1;
            char x=b[2],y=d[2];
            if(x>y)swap(x,y);
            if(y>='D'&&x<='C')cout<<"00";
            else{
                cout<<1;
                if(y==x+1)cout<<1;
                else cout<<0;
            }
        }
        else cout<<"000";
    }
    else cout<<"0000";
}