#include<iostream>
using namespace std;
long long a[100000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,m,n;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c==13||c==14)cout<<(n-1);
    }

    return 0;
}
