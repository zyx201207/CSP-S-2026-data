#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        cout<<x[n-n*n/4]<<endl;
    }
    return 0;
}
