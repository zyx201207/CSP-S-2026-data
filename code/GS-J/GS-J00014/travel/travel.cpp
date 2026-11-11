#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool p(char x,char y){
    return ('A'<=x&&x<='C'&&'A'<=y&&y<='C')||((x=='D'||x=='F')&&(y=='D'||y=='F'));
}bool q(char x,char y){
    return (x<='C'&&abs(x-y)==1)||(x>='D');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b.substr(0,2)==d.substr(0,2)){
            cout<<1;
            if(p(b[2],d[2])){
                cout<<1;
                if(q(b[2],d[2]))cout<<1;
                else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
