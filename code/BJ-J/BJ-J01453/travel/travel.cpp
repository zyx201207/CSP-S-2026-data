#include<bits/stdc++.h>
using namespace std;
struct node{
    string c,s;
};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    node a,b;
    cin>>a.c>>a.s>>b.c>>b.s;
    if(a.c==b.c){
        if(a.s==b.s-2||a.s==b.s+2||a.s==b.s+1||a.s==b.s-1){
            cout<<1111;
        }else{
            cout<<1100;
        }
    }
    else{
        cout<<0000;
    }
    return 0;
}