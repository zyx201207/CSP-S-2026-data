#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int ca,cb;
    string sa,sb;
    cin>>ca>>sa>>cb>>sb;
    if(ca!=cb){
        cout<<"0000"<<endl;
        return 0;
    }else{
        cout<<"1";
    }
    if(sa[0]!=sb[0]||sa[1]!=sb[1]){
        cout<<"000"<<endl;
        return 0;
    }else{
        cout<<"1";
    }
    if(sa[2]<='C'&&sb[2]>='D'){
        cout<<"00"<<endl;
        return 0;
    }else if(sa[2]>='D'&&sb[2]<='C'){
        cout<<"00"<<endl;
        return 0;
    }else{
        cout<<"1";
    }
    if(sa[2]=='A'&&sb[2]=='C'){
        cout<<"0"<<endl;
        return 0;
    }else if(sa[2]=='C'&&sb[2]=='A'){
        cout<<"0"<<endl;
        return 0;
    }else{
        cout<<"1"<<endl;
    }
    return 0;
}
