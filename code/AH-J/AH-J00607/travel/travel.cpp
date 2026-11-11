#include<bits/stdc++.h>
using namespace std;
int a,b;
string az,bz;
bool m;
bool issamec(int a,int b){
    if(a==b){
        return 1;
    }
    return 0;
}
bool issamep(string az,string bz){
    if(az[0]==bz[0]&&az[1]==bz[1]){
        return 1;
    }
    return 0;
}
bool issameg(string az,string bz){
    if((az[2]=='C'&&bz[2]=='D')||(az[2]=='D'&&bz[2]=='C')){
        return 0;
    }
    return 1;
}
bool issamel(string az,string bz){
    if(az[2]+1==bz[2]||az[2]-1==bz[2]){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>az>>b>>bz;
    if(issamec(a,b)){
        cout<<"1";
        m=1;
    }
    else{
        cout<<"0";
    }
    if(issamep(az,bz)&&m==1){
        cout<<"1";
    }
    else{
        cout<<"0";
        m=0;
    }
    if(issameg(az,bz)&&m==1){
        cout<<"1";
    }
    else{
        cout<<"0";
        m=0;
    }
    if(issamel(az,bz)&&m==1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
