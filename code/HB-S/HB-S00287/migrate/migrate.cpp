#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        int a[1000005];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(d<=a[n]-a[n-1])cout<<a[n]-a[n-1]<<endl;

    }
    return 0;
}
