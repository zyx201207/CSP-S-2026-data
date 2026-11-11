#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,aa,b,bb;
    char aaa,bbb;
    cin>>a>>aa>>aaa>>b>>bb>>bbb;
    if(a==b) cout<<1;
        else {
            cout<<0<<0<<0<<0;
            return 0;
        }
    if(aa==bb) {
        cout<<1;
        if(aaa<=67&&bbb<=67) cout<<1;
            else if(aaa>=68&&bb>=68) cout<<1;
                else cout<<0<<0;
        if(aaa<=67&&bbb<=67||aaa>=68&&bbb>=68){
            if(aaa+1==bbb||bbb+1==aaa) cout<<1;
                else cout<<0;
        }
    }else cout<<0<<0<<0;

    return 0;
}
