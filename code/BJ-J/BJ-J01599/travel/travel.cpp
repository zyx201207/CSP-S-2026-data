#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string n,m;
    cin>>a>>n>>b>>m;
    if(a==b){
        cout<<1;
        if(n[0]==m[0]&&n[1]==m[1]){
            char c=n[2],d=m[2];
            cout<<1;
            if(!((c<='C')^(d<='C'))){
                cout<<1;
                if(c<='C'){
                    if(c==d+1||c==d-1) cout<<1;
                    else cout<<0;
                }else cout<<1;

            }else cout<<"00";
        }
        else cout<<"000";
    }else cout<<"0000";
    return 0;
}
