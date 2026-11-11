#include<bits/stdc++.h>
using namespace std;
int c1,c2;
struct a{
    int n;
    char id;
}s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1.n>>s1.id>>c2>>s2.n>>s2.id;
    if(c1==c2){
        cout<<1;
        if(s1.n==s2.n){
            cout<<1;
            if((s1.id>='A'&&s1.id<='C')&&(s2.id>='A'&&s2.id<='C')){
                cout<<1;
                if((s1.id+1)==s2.id||(s1.id-1)==s2.id){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else if((s1.id>='D'&&s1.id<='F')&&(s2.id>='D'&&s2.id<='F')){
                cout<<1;
                if((s1.id+2)==s2.id||(s1.id-2)==s2.id){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
