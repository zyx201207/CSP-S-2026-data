#include<bits/stdc++.h>
using namespace std;
long  n,m,a[1000010],x;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
       if(a[i]-a[1]==a[i-1]){
            cout<<n-2;
       }
    }
    return 0;
}
