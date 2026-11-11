#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a1[3],b1[3],w,s;
    int x,y,a,b;
    cin>>x>>a1>>y>>b1;
    w=a1[2];
    s=b1[2];
    if(x!=y){
        cout<<"0000";
        return 0;
    }
    a=(a1[0]-'0')*10+(a1[1]-'0');
    b=(b1[0]-'0')*10+(b1[1]-'0');
    if(a!=b){
        cout<<"1000";
        return 0;
    }
    if(w>='D'&&s<='C'){
        cout<<"1100";
        return 0;
    }
    if(s>='D'&&w<='C'){
        cout<<"1100";
        return 0;
    }
    if(s=='A'&&w=='C'){
        cout<<"1110";
        return 0;
    }
    if(w=='A'&&s=='C'){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
