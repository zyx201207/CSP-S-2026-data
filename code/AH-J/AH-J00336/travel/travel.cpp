#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    string a1=s1.substr(0,2);
    string a2=s2.substr(0,2);
    if(a1==a2){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    string a3=s1.substr(2,1);
    string a4=s2.substr(2,1);
    if(a3=="D"&&a4=="F"||a3=="F"&&a4=="D"){
        cout<<"11";
    }else if(a3=="A"&&a4=="B"||a3=="A"&&a4=="C"||a3=="B"&&a4=="C"||a3=="B"&&a4=="A"||a3=="C"&&a4=="B"||a3=="C"&&a4=="A"){
        if(a3=="A"&&a4=="C"||a3=="C"&&a4=="A"){
            cout<<"10";
        }else{
            cout<<"11";
        }
    }else{
        cout<<"00";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
