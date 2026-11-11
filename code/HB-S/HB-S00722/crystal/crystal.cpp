#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout)
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0]+a[1]>=0){
        cout<<a[0]+a[1];
    }
    if(a[0]+a[1]<0){
        cout<<-(a[0]+a[1]);
    }

    return 0;
}
