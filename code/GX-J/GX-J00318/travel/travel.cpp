#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool pow1=(c1==c2);
    char ss1=s1[2],ss2=s2[2];
    s1[2]='0';s2[2]='0';
    bool pow2=0;
    if(pow1)pow2=(s1==s2);
    bool pow3=0,pow4=0;
    if(pow2){
    if(ss1=='D'||ss1=='F'){
        if(ss2=='D'||ss2=='F'){
            pow3=1;pow4=1;
        }
    }
    else{
        if(ss2=='D'||ss2=='F')pow3=0;
        else{
            pow3=1;
            if(ss2-ss1==1||ss1-ss2==1)pow4=1;
        }
    }}
    cout<<pow1<<pow2<<pow3<<pow4;
    return 0;
}
