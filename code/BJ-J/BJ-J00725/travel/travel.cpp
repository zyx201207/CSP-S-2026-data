#include<bits/stdc++.h>
using namespace std;
bool flag1,flag2,flag3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a3;
    string a2,a4,ans="";
    cin>>a1>>a2>>a3>>a4;
    if(a1==a3){
            flag1=1;
        ans+='1';
    }else{
        ans+='0';
    }
    if(a2[0]==a4[0]&&a2[1]==a4[1]&&flag1){
        flag2=1;
        ans+='1';
    }else{
        ans+='0';
    }
    if(flag2&&((a2[2]<='C'&&a4[2]<='C')||(a2[2]>'C'&&a4[2]>'C'))){
        flag3=1;
        ans+='1';
    }else{
        ans+='0';
    }
    if(flag3&&(a4[2]-a2[2]==1||a2[2]-a4[2]==1)){
        ans+='1';
    }else{
        ans+='0';
    }
    cout<<ans;
    return 0;
}
