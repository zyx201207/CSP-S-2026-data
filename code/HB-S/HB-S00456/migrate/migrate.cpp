#include <bits/stdc++.h>
using namespace std;
long long MAX=2e6+5;
long long c, t, n, d, x[MAX];
int main(){
    freopen("migrate.in","r",stdin);
    cin>>c>>t;
    for(long long i=0; i<t; i++)
    {
        cin>>n>>d;
        for(long long j=0; j<n; j++)
        {
            cin>>x[i];
        }
        cout<<n/2<<endl;
    }
    freopen("migrate.out","w",stdout);
    return 0;
}
