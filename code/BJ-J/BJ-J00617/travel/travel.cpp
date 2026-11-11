#include<algorithm>
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    int c1,c2,s1,s2,ans=0000;
    char a,b,s11,s22;
    cin>>c1>>s1>>s11>>c2>>s2>>s22;
    if(c1==c2){
        ans+=1000;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }

    if(s1==s2){
        ans+=100;
    }
    else{
        cout<<ans;
        return 0;
    }

    if((((s11=='A')||(s11=='B'))||(s11=='C'))&&((s22=='A')||(s22=='B'))||(s22=='C')){
        ans+=10;
    }
    else if(((s11=='D')||(s11=='F'))&&((s22=='D')&&(s22=='F'))){
        ans+=11;
        cout<<ans;
        return 0;
    }
    else{
        cout<<ans;
        return 0;
    }
    if((s11=='A')&&(s22=='B')){
        ans+=1;
    }
    else if((s11=='B')&&((s22=='A')||(s22=='C'))){
        ans+=1;
    }
    else if((s11=='C')&&(s22=='B')){
        ans+=1;
    }
    else{
        cout<<ans;
        return 0;
    }
    cout<<ans;
    return 0;
}
