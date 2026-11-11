#include <bits/stdc++.h>

using namespace std;
long long c,t,n,d,a[500006];

int main()
{
    freopen("migrate.in","r",stdin);
     freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)cin>>a[i];
        if(d>=2*(a[2]-a[1])){
            cout<<n-2;
        }
        else cout<<0;
    }
    return 0;
}
