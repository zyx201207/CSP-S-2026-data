#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool a=true;
    for(int i=0;i<=1;i++){
        if(c1[i]!=c2[i]){
            a=false;
        }
    }
    if(a==true){
        cout<<1;
    }else{
        cout<<0;
    }
    for(int i=0;i<=1;i++){
        if(s1[i]!=s2[i]){
            a=false;
        }
    }
    if(a==true){
        cout<<1;
    }else{
        cout<<0;
    }
    if(s1[2]<='C'&& s1[2]>='A' && s2[2]>='D' && s2[2]<='F'){
            a=false;
    }
    if(s2[2]<='C'&& s2[2]>='A' && s1[2]>='D' && s1[2]<='F'){
            a=false;
    }
    if(a==true){
        cout<<1;
    }else{
        cout<<0;
    }
    int b=s1[2]-s2[2];
    if(b<0){
        if(b!=-1){
            a=false;
        }
    }
    if(b>0){
        if(b!=1){
            a=false;
        }
    }
    if(a==true){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
}
