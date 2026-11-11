#include <bits/stdc++.h>
using  namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!="01" && a!="16" && c!="01" && c!="16" && a==c){
        cout<<"1";
        if(b[0]==d[0] && b[1]==d[1]){
            cout<<"1";
            int f=1,e=1;
            if(b[2]=='C' || b[2]=='D') f=2;
            if(d[2]=='C' || d[2]=='D') e=2;
            if(f==e){
                cout<<"1";
                if(b[2]==d[2]-1 || b[2]==d[2]+1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
