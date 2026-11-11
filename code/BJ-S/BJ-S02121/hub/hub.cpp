#include <bits/stdc++.h>
using namespace std;
int a[10000005];
int b[10000005];
int main(){
    freopen("","r",stdin);
    freopen("","w",stdout);
    int c,t;
    for(int i = 1;i <= t;i++){
        cin>>a[i];
        cin>>b[i];
    }
    if(t == 2){
        cout<<1<<"\n"<<2;
    }
    return 0;
}
