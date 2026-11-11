#include <bits/stdc++.h>
using namespace std;
int x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.in","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--){
        int n,d;
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>x[i];
        }
        cout<<n/2<<"\n";
    }
    return 0;
}
