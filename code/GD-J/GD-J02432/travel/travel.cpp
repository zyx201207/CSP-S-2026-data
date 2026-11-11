#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int z[6]={1,2,3,4,0,5},z2[6]={0,0,0,1,0,1};
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    cout<<'1';
    string c1,c2,d1,d2;
    c1+=c[0];
    c1+=c[1];
    c2+=c[2];
    d1+=d[0];
    d1+=d[1];
    d2+=d[2];
    if(c1==d1){
        cout<<'1';
    }else{
        cout<<"000";
        return 0;
    }
    if(z2[c2[0]-65]==z2[d2[0]-65]){
        cout<<'1';
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(z[c2[0]-65]-z[d2[0]-65])==1){
        cout<<'1';
    }else{
        cout<<'0';
    }
    cout<<' '<<c2[0]-65<<' '<<d2[0]-65;
    return 0;
}
