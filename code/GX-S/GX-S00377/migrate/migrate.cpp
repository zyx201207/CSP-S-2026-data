#include<bits/stdc++.h>
using namespace std;
int a[2500001];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        int x=a[3]-a[2];
        if(2*x>d)cout<<"0\n";
        else cout<<2*n-2*(d/x)-1;
    }
    return 0;
}

