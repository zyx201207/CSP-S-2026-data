#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ac,bc,az,bz;
    cin>>ac>>az>>bc>>bz;
    int a_c=10*(ac[0]-'0')+(ac[1]-'0');
    int b_c=10*(bc[0]-'0')+(bc[1]-'0');
    int a_p=10*(az[0]-'0')+(az[1]-'0');
    int b_p=10*(bz[0]-'0')+(bz[1]-'0');
    char a_l=az[2];
    char b_l=bz[2];
    if(a_c==b_c){
        cout<<1;
        if(a_p==b_p){
            cout<<1;
            if((a_l<='C'&& b_l<='C')||(a_l>='D'&& b_l>='D')){
                cout<<1;
                if(abs(int(a_l-b_l))==1 || (a_l>='D'&& b_l>='D')) cout<<1;
                else cout<<0;
            }else cout<<0<<0;
        }else cout<<0<<0<<0;
    }else cout<<0<<0<<0<<0;
    return 0;
}//NOI let me AC
