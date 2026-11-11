#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x,y;
    string a,b;
    cin>>x>>a>>y>>b;
    if(x==y){
        cout<<1;
    }else{
    cout<<"0000";
    return 0;
    }if(a[0]==b[0]&&a[1]==b[1]){
    cout<<1;
    }else{
    cout<<"000";
    return 0;
    }if((a[2]<='C'&&b[2]<='C')||(a[2]>='D'&&b[2]>='D')){
        cout<<1;
    }else{
    cout<<"00";
    return 0;
    }if(a[2]+1==b[2]||a[2]-1==b[2]){
    cout<<1;
    }else{
    cout<<0;
    }
return 0;
}
