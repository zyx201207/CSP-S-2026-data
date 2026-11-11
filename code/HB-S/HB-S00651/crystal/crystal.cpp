#include <bits/stdc++.h>
using namespace std;
int a[1000000000000+5],x,y,z;
int main(){
    freopen("crystal"in"r",sitin);
    freopen("crystal"out"w",sitout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        if(a[i+n]==a[i+y]==a[i]){
            z++;
        }
    }
    cout<<z;
    return 0;
}
