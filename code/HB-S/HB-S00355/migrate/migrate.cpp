#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        int a[2000010];
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int ans=0;
        ans=(d+d-1)/(a[2]-a[1])+1;
        if((d+d-1)%(a[2]-a[1])==0)
        {
            cout<<n-ans+1;
        }
        else cout<<0;
    }
    return 0;
}
//௹௹௹௹
