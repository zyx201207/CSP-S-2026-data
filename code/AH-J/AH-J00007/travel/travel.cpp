#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        ll x=(b[0]-'0')*10+(b[1]-'0');
        ll y=(d[0]-'0')*10+(d[1]-'0');
        if(x==y){
            cout<<1;
            a=b[2];
            c=d[2];
            if((a<="C"&&c<="C")||(a>"C"&&c>"C")){
                cout<<1;
                x=a[0]-'0';
                y=c[0]-'0';
                if(abs(x-y)==1)cout<<1;
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    return 0;
}
