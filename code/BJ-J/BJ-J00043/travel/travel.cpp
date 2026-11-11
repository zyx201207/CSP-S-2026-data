#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
                if(d[2]=='A'||d[2]=='B'||d[2]=='C') cout<<1;
                else cout<<0;
            }
            else{
                if(d[2]=='D'||d[2]=='F') cout<<1;
                else cout<<0;
            }
            if(char(b[2]+1)==char(d[2])||char(b[2]-1)==char(d[2])) cout<<1;
            else cout<<0;
        }
        else cout<<"000";  
    }else cout<<"0000";
    return 0;
}