#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(s2[0]==s4[0]&&s2[1]==s4[1]){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    char c1=s2[2],c2=s4[2];
    if((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C')||
       (c1=='D'||c1=='E')&&(c2=='D'||c2=='E')){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(c2-c1==1&&c1!='C'){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
