#include<bits/stdc++.h>
using namespace std;
int c,c2;
string s,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s;
    cin>>c2>>s2;
    if(c==c2){
        cout<<1;
        int a=(s[0]-'0')*10+s[1]-'0';
        int b=(s2[0]-'0')*10+s2[1]-'0';
        if(a==b){
            cout<<1;
            if(s[2]<='C'&&s2[2]<='C'||s[2]>'C'&&s2[2]>'C'){
                cout<<1;
                if(s[2]+1==s2[2]||s2[2]+1==s[2]){
                    cout<<1;
                }else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
