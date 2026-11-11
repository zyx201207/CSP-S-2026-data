#include <bits/stdc++.h>
using namespace std;
string b[18],b2[18];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c,c2;
    string s,s2;
    cin>>c>>s>>c2>>s2;
    if(c!=c2){
        cout<<0<<0<<0<<0;
        return 0;
    }
    else{
        cout<<1;
    }
    for(int i=1;i<=3;i++){
        int f=0;
        for(int j=1;j<=18;j++){
            b[j]+=s;
            b2[j]+=s2;
            if(b[j+1]==b2[j]||b[j]==b2[j+1]){
               f=1;
               break;
            }
        }
        if(f==1){
            cout<<1;
            f=0;
        }
        else{
            cout<<0;
        }
    }

return 0;
}
