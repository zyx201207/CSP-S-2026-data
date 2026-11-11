#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(m==1) cout <<0<<endl;
        else if(n-2<m) cout <<0<<endl;
        else cout <<n-m-1<<endl;
    }
    return 0;
}
