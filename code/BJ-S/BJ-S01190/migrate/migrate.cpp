#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000005];
int f[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        int dd=x[2]-x[1];
        if(2*dd>d)
        {
            cout<<0;
        }
        else
        {
            cout<<n-2;
        }
        cout<<endl;
    }
    return 0;
}