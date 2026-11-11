#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,c3,c4;
    char s1,s2;
    cin>>c1>>c3>>s1;
    cin>>c2>>c4>>s2;
    if(c1==c2){
        cout<<1;
        if(c3==c4){
            cout<<1;
            if(s1<='C'&&s2<='C'||
               s1>'C'&&s2>'C'){
                    cout<<1;
                    if(abs((int)s1-(int)s2)==1) cout<<1;
                    else cout<<0;
               }else cout<<0<<0;
        }else cout<<0<<0<<0;

    }else cout<<0<<0<<0<<0;
    return 0;
}
