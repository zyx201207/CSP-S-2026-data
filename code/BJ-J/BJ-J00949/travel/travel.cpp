#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        char se1=s1[2],se2=s2[2];
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if((se1<='C'&&se2<='C')||(se1>='D'&&se2>='D')){
                cout<<1;
                if((se1=='D'&&se2=='F')||(se1=='F'&&se2=='D')||(se1+1==se2)||(se1==se2+1))cout<<1;
                else cout<<0;
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