#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<"1";
    string u="",v="";
    for(int i=0;i<2;i++){
        u+=s1[i];
        v+=s2[i];
    }
    if(u!=v){
        cout<<"000"<<endl;
        return 0;
    }
    cout<<"1";
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
        cout<<"1";
    }else{
        cout<<"00"<<endl;
        return 0;
    }
    if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
        cout<<"1"<<endl;
    }else{
        cout<<"0"<<endl;
    }
    return 0;
}
