#include<bits/stdc++.h>
using namespace std;
string an,bn;
int aid,bid;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>aid>>an>>bid>>bn;
    if(aid!=bid){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    int a=0,b=0;
    char ac,bc;
    for(int i=0;i<an.size();i++){
        while(an[i]>='0'&&an[i]<='9'){
            a*=10;
            a+=an[i++]-'0';
        }
        ac=an[i];
    }
    for(int i=0;i<bn.size();i++){
        while(bn[i]>='0'&&bn[i]<='9'){
            b*=10;
            b+=bn[i++]-'0';
        }
        bc=bn[i];
    }
    if(a!=b){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(!(((ac=='A'||ac=='B'||ac=='C')
            &&(bc=='A'||bc=='B'||bc=='C'))
         ||((ac=='D'||ac=='E')
            &&(bc=='D'||bc=='E')))){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(abs(ac-bc)!=1){
        cout<<0;
        return 0;
    }
    cout<<1;
    return 0;
}