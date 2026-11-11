#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int pd;
    cin>>c1>>s1>>c2>>s2;
    char cs1,cs2;
    cs1=c1[0]+c1[1];
    cs2=c2[0]+c2[1];
    if(cs1==cs2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    cs1=s1[0]+s1[1];
    cs2=s2[0]+s2[1];
    if(cs1==cs2){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    cs1=s1[2];
    cs2=s2[2];
    int chazhi=abs(cs1-cs2);
    if((cs1=='F'&&cs2=='D')||(cs1=='D'&&cs2=='F')){
        cout<<"11";
        return 0;
    }
    else if((cs1=='C'&&cs2=='D')||(cs1=='D'&&cs2=='C')){
        cout<<"00";
        return 0;
    }
    else if((cs1=='C'&&cs2=='A')||(cs1=='A'&&cs2=='C')){
        cout<<"10";
        return 0;
    }
    else if(chazhi==1){
        cout<<"11";
        return 0;
    }
    else if(chazhi>1){
        cout<<"10";
        return 0;
    }
    return 0;
}



