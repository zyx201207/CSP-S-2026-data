#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    int cnt=0;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;
    }
    for(int i=0;i<c.size();i++){
        if(c[i]==d[i] &&i==0 or i==3){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;

}

