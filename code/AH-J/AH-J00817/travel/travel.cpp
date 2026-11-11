#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    string c1,c2,s1,s2;
    string n="",m="";
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    n=n+s1[0]+s1[1];
    m=m+s2[0]+s2[1];
    if(n==m){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(s1[2]>='D'&&s2[2]>='D'){
        cout<<"1";
    }else{
        int w=(int)s1[2]-s2[2];
        if(w==1||w==-1){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
    return 0;
}



















