#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a>>b>>c>>d;

    e=b[0]+b[1];f=d[0]+d[1];
    if(a==c)cout<<1;
    else cout<<0;
    if(a==c && e==f)cout<<1;
    else cout<<0;

    if(a==c && e==f){
        if(b[2]=='D' || b[2]=='F'){
            if((d[2]=='D' || d[2]=='F' ))cout<<1;
        }
        else if((d[2]=='D' || d[2]=='F' )){
            cout<<0;
        }
        else cout<<1;
    }
    else cout<<0;



    if(a==c && e==f){
        if(b[2]=='D' || b[2]=='F'){
            if((d[2]=='D' || d[2]=='F' ))cout<<1;
        }
        else if((d[2]=='D' || d[2]=='F' )){
            cout<<0;
        }
        else if(b[2]+1==d[2] || b[2]-1==d[2]){
            cout<<1;
        }
        else cout<<0;
    }
    else cout<<0;






return 0;
    }