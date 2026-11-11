#include<bits/stdc++.h>
using namespace std;
int a,b;
char a1[10],b1[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1>>b>>b1;

    if(a!=b){
        cout<<"0000";
        return 0;
    }

    if(!(a1[0]==b1[0] && a1[1]==b1[1])){
        cout<<"1000";
        return 0;
    }

    bool flag1=0,flag2=0;
    if(a1[2]=='A' || a1[2]=='B' || a1[2]=='C') flag1=1;
    if(b1[2]=='A' || b1[2]=='B' || b1[2]=='C') flag2=1;
    if(flag1!=flag2){
        cout<<"1100";
        return 0;
    }

    if(abs(a1[2]-b1[2])!=1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
