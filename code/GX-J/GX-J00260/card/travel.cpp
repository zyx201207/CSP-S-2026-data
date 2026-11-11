#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b;
    int x,y;
    cin>>x>>a;
    cin>>y>>b;
    if(x==y){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }


    if(a[0]==b[0] && a[1]==b[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }

    if('D'-a[2]>=1 &&'D'-b[2]>=1 || a[2]-'D'>=0 && b[2]-'D'>=0){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }

    if(a[2]-b[2]==1||b[2]-a[2]==1){
        cout<<1;
    }
    else{
        cout<<"0";
    }

}
