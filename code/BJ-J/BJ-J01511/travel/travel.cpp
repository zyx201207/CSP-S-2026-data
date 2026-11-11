#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            cout<<"0000";
            return 0;
        }
    }
    cout<<1;
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<1;
    if(s1[2]<=int('C')&&s2[2]<=int('C')){
        cout<<1;
        if(abs(s1[2]-s2[2])==1){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(s1[2]>=int('D')&&s2[2]>=int('D')){
        cout<<"11";
    }else{
        cout<<"00";
    }
    return 0;
}
