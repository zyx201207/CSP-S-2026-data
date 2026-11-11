#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b) cout<<"1";
    else cout<<"0";
    int l=c[0]*10+c[1],r=d[0]*10+d[1];
    if(l==r){
        cout<<"1";
        cout<<"1";

    }
    else {
        cout<<"0";
        cout<<"0";

    }
    cout<<"1";
    return 0;
}

