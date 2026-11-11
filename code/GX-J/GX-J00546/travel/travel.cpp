#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    //("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[1]-'0'==c2[1]-'0'){
        cout<<1;
    }else{
        cout<<0;
    }
    if(s1[1]-'0'==s2[1]-'0'){
        cout<<1;
    }else{
        cout<<0;
    }
    int a1=s1[2]-'A';
    int a2=s2[2]-'A';
    if(a1==0||a1==1||a1==2&&a2==0||a2==1||a2==2){
        cout<<1;
    }else if(a1==3||a1==4&&a2==3||a2==4){
        cout<<1;
    }else{
        cout<<0;
    }
    if(a1-a2==1||a2-a1==1){
        cout<<1;
    }else{
        cout<<0;
    }


    return 0;
}
