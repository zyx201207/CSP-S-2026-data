#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a,b,aa,bb;char A,B;
    cin>>a>>aa>>A>>b>>bb>>B;
    if(a==b){
        cout<<1;
        if(aa==bb){
            cout<<1;
            if((A<='C'&&B<='C')||(A>='D'&&B>='D')){
                cout<<1;
                if(A-B==1||B-A==1)cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
