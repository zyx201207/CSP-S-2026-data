#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d;
        cin>>n>>d;
        int a[n];
        for(int i=0;i<d;i++) cin>>a[i];
        if(d<=3) cout<<0;
    }
    return 0;
}