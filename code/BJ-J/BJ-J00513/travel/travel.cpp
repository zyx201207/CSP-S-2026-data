#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int x=(s1[0]-'0')*10+(s1[1]-'0'),y=(s3[0]-'0')*10+(s3[1]-'0'),xl=(s2[0]-'0')*10+(s2[1]-'0'),yl=(s4[0]-'0')*10+(s4[1]-'0'),xr=(s2[2]-'A'),yr=(s4[2]-'A');
    if(x!=y){
        cout<<"0000";
        return 0;
    }
    if(xl!=yl){
        cout<<"1000";
        return 0;
    }
    if((xr<=2&&yr>2)||(xr>2&&yr<2)){
        cout<<"1100";
        return 0;
    }
    if(abs(xr-yr)>1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}