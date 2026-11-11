#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(b.substr(0,2)==d.substr(0,2)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(b.substr(0,2)==d.substr(0,2)&&((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))){
            cout<<1;
    }else cout<<0;
    if((a==c)&&
    b.substr(0,2)==d.substr(0,2)&&((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
    &&abs((d[d.size()-1]-'0')-(b[b.size()-1]-'0'))==1){
        cout<<1;
    }else cout<<0;
    return 0;
}
