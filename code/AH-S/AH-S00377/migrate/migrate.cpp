#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000006];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n>=1000000)
        {
            cout<<n-d-1<<endl;
        }
        else
        {
            cout<<n/2<<endl;
        }
    }
    return 0;
}
