#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,c1,s1;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=18;j++){
            cin>>c>>s>>c1>>s1;
            if(c==c1){
                cout<<1;
            }else{
                cout<<0;
            }
            if(c==c1&&s==s1){
                cout<<1;
            }else{
                cout<<0;
            }
        }
    }
    return 0;
}
