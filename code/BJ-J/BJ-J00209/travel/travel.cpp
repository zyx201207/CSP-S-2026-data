#include<bits/stdc++.h>
using namespace std;
struct node{
    char a1,a2,b1,b2,c;
}r,x;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r.a1>>r.a2>>r.b1>>r.b2>>r.c;
    cin>>x.a1>>x.a2>>x.b1>>x.b2>>x.c;
    if(r.a1==x.a1&&r.a2==x.a2){
        cout<<'1';
        if(r.b1==x.b1&&r.b2==x.b2){
            cout<<'1';
            if((r.c-'A'<=2&&x.c-'A'<=2)||(r.c-'A'>=3&&x.c-'A'>=3)){
                cout<<'1';
                if(abs((r.c-'A')-(x.c-'A'))==1) cout<<'1';
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
