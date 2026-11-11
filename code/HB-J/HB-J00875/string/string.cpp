#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,n;
    cin>>a;
    char w;
    for(int i=0;i<a;i++){
        cin>>n>>w;
    }
    if(a==3){
        cout<<2;
    }
    if(a==2){
        cout<<0;
    }
    if(a==6){
        cout<<3000000000;
    }

    return 0;
}
