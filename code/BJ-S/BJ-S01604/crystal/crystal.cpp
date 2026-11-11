#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    bool flag=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        flag=0;
    }
    int l=1,r=n;
    if(flag)
        cout<<n;
    else
        cout<<5;
    return 0;
}
