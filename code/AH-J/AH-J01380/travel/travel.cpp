#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    string q="",p="";
    q+=s1[0];
    q+=s1[1];
    p+=s2[0];
    p+=s2[1];
    if(q!=p){
        cout<<"1000";
        return 0;
    }
    if(!(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
        cout<<"1100";
        return 0;
    }
    if(abs(s1[2]-s2[2])==1){
        cout<<"1111";
    }
    else{
        cout<<"1110";
    }
    return 0;
}
