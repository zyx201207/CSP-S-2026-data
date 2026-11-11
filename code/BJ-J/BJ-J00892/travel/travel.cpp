#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string a[2],b[2],c[2]={"",""};
    char bs[2];
    bool ft,tf,fta;
    cin>>a[0]>>b[0]>>a[1]>>b[1];
    bs[0]=b[0][b[0].size()-1];
    bs[1]=b[1][b[1].size()-1];
    for(int i=0;i<b[0].size()-1;i++){
        c[0]+=b[0][i];
    }
    for(int i=0;i<b[1].size()-1;i++){
        c[1]+=b[1][i];
    }
    if(a[0]==a[1]){
        cout<<1;
        ft=true;
    }
    else{
        cout<<0;
        ft=false;
    }
    if(ft==false){
        cout<<"000";
        return 0;
    }
    if(c[0]==c[1]){
        cout<<1;
        tf=true;
    }
    else{
        cout<<0;
        tf=false;
    }
    if(tf==false){
        cout<<"00";
        return 0;
    }
    if((bs[0]<='C'&&bs[1]<='C')||(bs[0]>='D'&&bs[1]>='D')){
        cout<<1;
        fta=true;
    }
    else{
        cout<<0;
        fta=false;
    }
    if(fta==false){
        cout<<0;
        return 0;
    }
    if(max(bs[0]-'A',bs[1]-'A')-min(bs[0]-'A',bs[1]-'A')==1&&((!(bs[0]=='C'&&bs[1]=='D'))&&(!(bs[0]=='D'&&bs[1]=='C')))){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
