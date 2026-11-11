#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    char a1[4],b1[4];
    cin>>a>>a1[1]>>a1[2]>>a1[3]>>b>>b1[1]>>b1[2]>>b1[3];
    if(a!=b){
        cout<<"0000";
        return 0;
    }else if(a1[1]!=b1[1]||a1[2]!=b1[2]){
        cout<<1000;
        return 0;
    }else if((a1[3]=='A'||a1[3]=='B'||a1[3]=='C')&&(b1[3]=='D'||b1[3]=='F') || (b1[3]=='A'||b1[3]=='B'||b1[3]=='C')&&(a1[3]=='D'||a1[3]=='F')){
        cout<<1100;
        return 0;
    }else if(a1[3]=='A'&&b1[3]=='C' || b1[3]=='A'&&a1[3]=='C'){
        cout<<1110;
        return 0;
    }else cout<<1111;
    return 0;
}
