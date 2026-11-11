#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[2000006],d,s,sd,c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    d=a[2]-a[1];
    s=m/d;
    sd=s*2-1;
    cout<<n-sd<<"\n";
    }

    return 0;
}

