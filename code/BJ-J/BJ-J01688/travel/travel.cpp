#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int y=0,m=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    for(int i=0;i<a.size();i++){
        if(a[i]!=c[i]){cout<<0<<0<<0<<0;
        return 0;}
    }
    cout<<1;
    for(int i=0;i<b.size()-1;i++){
        if(b[i]!=d[i]){cout<<0<<0<<0;
        return 0;}
    }
    cout<<1;
    if((b[b.size()-1]>='A'&&b[b.size()-1]<='C'&&d[d.size()-1]>'C')||(d[d.size()-1]>='A'&&d[d.size()-1]<='C'&&b[b.size()-1]>'C')){
        cout<<0<<0;
        return 0;
    }
    cout<<1;
    if(b[b.size()-1]!=d[d.size()-1]+1&&b[b.size()-1]!=d[d.size()-1]-1){
        cout<<0;
        return 0;
    }
    cout<<1;
    return 0;
}
