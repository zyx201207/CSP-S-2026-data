#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen(travel.in,"r",stdin);
    freopen(travel.out,"w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int cc1=c1[1]-'0'+(c1[0]-'0')*10;
    int cc2=c2[1]-'0'+(c2[0]-'0')*10;
    if(cc1!=cc2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    cc1=s1[1]-'0'+(s1[0]-'0')*10;
    cc2=s2[1]-'0'+(s2[0]-'0')*10;
    if(cc1!=cc2){
        cout<<"000";
        return 0;
    }
    cout<<1;
    char cf=s1[2],cs=s2[2];
    int flag1=0,flag2=0;
    if(cf=='A'||cf=='B'||cf=='C')flag1=1;
    if(cs=='A'||cs=='B'||cs=='C')flag2=1;
    if(flag1!=flag2){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(flag1==0){
        cout<<1;
        return 0;
    }
    if((cf-cs==1)||(cs-cf==1))cout<<1;
    else cout<<0;
    return 0;
}
