//GZ-J00267 贵阳市观山湖区第一高级中学 曹映森
#include <iostream>
#include <string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    string ans="";
    cin>>c1>>s1;
    cin>>c2>>s2;
    if(c1!=c2){
        ans="0000";
        cout<<ans;
        return 0;
    }
    ans+='1';
    string ns1=s1.substr(2);
    string ns2=s2.substr(2);
    string qs1=s1.substr(0,2);
    string qs2=s2.substr(0,2);
    if(qs1!=qs2){
        ans+="000";
        cout<<ans;
        return 0;
    }
    ans+='1';
    if((ns1=="A")||(ns1=="B")||(ns1=="C")){
        if((ns2=="D")||(ns2=="F")){
            ans+="00";
            cout<<ans;
            return 0;
       }
    }
    if((ns1=="D")||(ns1=="F")){
        if((ns2=="A")||(ns2=="B")||(ns2=="C")){
            ans+='00';
            cout<<ans;
            return 0;
       }
    }
    ans+='1';
    if(((ns1=="D")&&(ns2=="F"))||((ns1=="F")&&(ns2=="D"))){
        ans+='1';
        cout<<ans;
        return 0;
    }
    if((ns1=="A")&&(ns2=="B")){
        ans+='1';
        cout<<ans;
        return 0;
    }
    if((ns1=="B")&&(ns2=="C")){
        ans+='1';
        cout<<ans;
        return 0;
    }
    ans+='0';
    cout<<ans;
    return 0;
}
