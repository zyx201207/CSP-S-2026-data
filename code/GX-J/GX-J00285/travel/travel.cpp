#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(c1==c1){
        cout<<1;
    }
    string p1="";
    string p2="";
    for(int i=0;i<3;i++){
        if(s1[i]>='0' && s1[i]<='9'){
            p1+=s1[i];
        }
        if(s2[i]>='0' && s2[i]<='9'){
            p2+=s2[i];
        }
    }
    if(p1==p2){
        cout<<'1';
    }
    else{
        cout<<"000";
        return 0;
    }
    char w1=s1[2];
    char w2=s2[2];
    if(w1>='A' && w1<='C' && w2>='A' && w2<='C'){
        cout<<'1';
    }
    else if(w1>='D' && w2>='D'){
        cout<<'1';
    }
    else{
        cout<<"00";
        return 0;
    }
    if(w1+1==w2 || w1-1==w2){
        cout<<'1';
        return 0;
    }
return 0;
}
