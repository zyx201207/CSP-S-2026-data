#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("travel.in","r",stdin);
     freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(s1[2]<='C'&&s2[2]<='C'){
        cout<<1;

    }else if(s1[2]>'C'&&s1[2]<='F'&&s2[2]>'C'&&s2[2]<='F'){
    cout<<1;
    }else{
        cout<<0;
    }
    int z=max(s1[2],s2[2]);
    int x=min(s1[2],s2[2]);

    if(z-x==1){
        if(z==68&&x==67){
            cout<<0;
        }
        else cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
