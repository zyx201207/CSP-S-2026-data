#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,s1,s2;
    bool flag1=0,flag2=0;
    char s11,s22;
    cin>>c1>>s1>>s11>>c2>>s2>>s22;
    if((s11=='D'||s11=='F')){
        flag1=1;
    }
    if((s22=='D')||(s22=='F')){
        flag2=1;
    }
    if(c1==c2){
        cout<<1;
        if(s1==s2){
            cout<<1;
            if(flag1==flag2){
                cout<<1;
                if(abs((int)(s11-s22))==1){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";

        }
        else cout<<"000";
    }
    else {
        cout<<"0000";
    }


}
