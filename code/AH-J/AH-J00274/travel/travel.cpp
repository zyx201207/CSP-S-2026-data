#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c1,c2,z1,z2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>z1>>c2>>z2;
    for(int i=0;i<=1;i++){
        if(c1[i]!=c2[i]){
            cout<<"0000";
            return 0;
        }
    }
    cout<<1;
    for(int i=0;i<=1;i++){
        if(z1[i]!=z2[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<1;
    if(z1[2]=='D'||z1[2]=='F'){
        if(z2[2]=='D'||z2[2]=='F'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
    }else{
        if(z2[2]=='D'||z2[2]=='F'){
            cout<<"00";
            return 0;
        }else{
            cout<<1;
        }
    }
    if(max(z2[2],z1[2])-min(z2[2],z1[2])==1){
        cout<<1;
    }else{
        cout<<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
