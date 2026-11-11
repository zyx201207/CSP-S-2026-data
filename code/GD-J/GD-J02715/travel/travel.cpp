#include <bits/stdc++.h>
#include <cmath>
#include <string>
using namespace std;
string c1,s1,c2,s2,x;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        x+='1';
    }else{
        x+='0';
        x+='0';
        x+='0';
        x+='0';
        cout<<x<<endl;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        x+='1';
    }else{
        x+='0';
        x+='0';
        x+='0';
        cout<<x<<endl;
        return 0;
    }
    if((s1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
        x+='1';
    }else{
        x+='0';
        x+='0';
        cout<<x<<endl;
        return 0;
    }
    if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
        x+='0';
        cout<<x<<endl;

    }
    if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
        x+='1';
    }else{
        x+='0';
    }
    cout<<x<<endl;
    return 0;

}
