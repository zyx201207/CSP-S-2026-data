#include<bits/stdc++.h>
using namespace std;
int main(){
    /*freopen("travel1.in","r",stdin);
    freopen("travel1.out","w",stdout);*/
    string s1,z1,s2,z2;
    cin>>s1>>z1>>s2>>z2;
    bool flag=1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(z1[0]==z2[0]&&z1[1]==z2[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(((z1[2]=='A'||z1[2]=='B'||z1[2]=='C')&&(z2[2]=='A'||z2[2]=='B'||z2[2]=='C'))||((z1[2]=='D'||z1[2]=='F')&&(z2[2]=='D'||z2[2]=='F'))){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(((z1[2]=='A'||z1[2]=='B')&&(z2[2]=='B'||z2[2]=='A'))||((z1[2]=='B'||z1[2]=='C')&&(z2[2]=='C'||z2[2]=='B'))||((z1[2]=='D'||z1[2]=='E')&&(z2[2]=='E'||z2[2]=='D'))){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
