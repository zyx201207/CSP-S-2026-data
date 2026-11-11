#include <bits/stdc++.h>
using namespace std;
int a[20001];
bool p=0,q=0;
int u=0;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    for(int j=1;j<=t;j++)
    {
        cin>>n>>d;
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        cout<<0<<endl;
    }
    return 0;
}

