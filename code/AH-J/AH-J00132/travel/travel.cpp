#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,jg="";
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
       cout<< "0000";
       return 0;
    }
    else{
       jg+='1';
    }
    int z1,z2;
    z1=s1[0]-'0';
    z1=z1*10+(s1[1]-'0');
    z2=s2[0]-'0';
    z2=z2*10+(s2[1]-'0');
    if(z1!=z2){
        cout<<"1000";
        return 0;
    }
    else{
        jg+='1';
    }
    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
        if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
            jg+='1';
        }
        else{
            cout<<"1100";
            return 0;
        }
    }
    else if(s1[2]=='C' || s1[2]=='D'){
        if(s2[2]=='C' || s2[2]=='D'){
            jg+='1';
        }
        else{
            cout<<"1110";
            return 0;
        }
    }
    if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1){
        jg+='1';
    }
    else{
        jg+='0';
    }
    cout<<jg;
    return 0;
}
