#include<bits/stdc++.h>
using namespace std;
int main(){
    frepoen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,aps,bps;
    char az,bz;
    cin>>a>>aps>>az>>b>>bps>>bz;
    if(a==b){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(aps==aps){
        cout<<1;
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if((az=='a'||az=='b'||az=='c')&&(bz=='a'||bz=='b'||bz=='c')){
        cout<<1;
    }
    else{
        cout<<0<<0;
        return 0;
    }
    if(az+1==bz||az-1==bz){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
