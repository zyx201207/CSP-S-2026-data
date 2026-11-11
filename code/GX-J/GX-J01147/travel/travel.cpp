#include<bits/stdc++.h>
using namespace std;
    string a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    for(int i=0;i<2;i++){
        if(a1[i]!=b1[i]){
            cout<<0<<0<<0<<0;
        return 0;
        }
    }
    cout<<1;
    for(int i=0;i<2;i++){
        if(a2[i]!=b2[i]){
            cout<<0<<0<<0;
            return 0;
        }
    }
    cout<<1;
    if((a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C')||(a2[2]>='D'&&a2[2]<='E'&&b2[2]>='D'&&b2[2]<='E')){
        cout<<1;
    }
    else{
        cout<<0<<0;
        return 0;
    }
    if((a2[2]=='A'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='A')){
        cout<<0;
    }
    else cout<<1;
return 0;
}
