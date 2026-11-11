#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int x,y,z;
    int a=0,b;vector<int>s(x);
    cin>>x>>y;
    for(int i=0;i<x;i++){
        cin>>s[i];
    }
    for(int j=62;j>=0;j--){
        b=a|(1LL<<j);
        z=0;
        for(int i=0;i<x;i++){
            if(((s[i]&b)==b)&&(++z>=y)){
                break;
            }
        }
        if(z>=y){
            a=b;
        }
    }cout<<a;
    return 0;
}
