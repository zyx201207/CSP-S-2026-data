#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int zero=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        zero++;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<1;
            zero++;
            if((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C')){
                cout<<1;
                zero++;
                if(abs(s1[2]-s2[2])==1){
                    cout<<1;
                    zero++;
                }
            }
        }
    }
    for(int i=zero;i<4;i++){
        cout<<0;
    }
    return 0;
}
