#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    bool ture,flace;
    cin>>a>>b>>c>>d;
    for(int s=1;s<=17;s++){
        if(a==1&&c==1) cout<<0<<0;
        else if(a==16&&c==16) cout<<0<<0;
        else cout<<1<<1;
    }
    for(int i=1;i<=18;i++){
        if(b==d) cout<<1<<1;
        else cout<<0<<0;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
