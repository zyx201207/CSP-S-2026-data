#include<bits/stdc++.h>
using namespace std;
long long a[500005],m;
long long q[500005];
int n;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    if(n==1)
    {
        cin>>a[1];
        cout<<1;
    }
    else if(n==2)
    {
        cin>>a[1]>>a[2];
        if(a[2]-a[1]<=m) cout<<2;
        else cout<<1;
    }
    else if(n==3)
    {
        cin>>a[1]>>a[2]>>a[3];
        sort(a+1,a+1+3);
        if((a[3]-a[2])+(a[3]-a[1])<=m) cout<<3;
        else if(((a[3]-a[2])<=m) || ((a[3]-a[1])<=m)|| ((a[2]-a[1])<=m)) cout<<2;
        else cout<<1;
    }
    else if(n==4)
    {
        cin>>a[1]>>a[2]>>a[3]>>a[4];
        sort(a+1,a+1+4);
        if((a[4]-a[3])+(a[4]-a[2])+(a[4]-a[1])<=m) cout<<4;
        else if(((a[4]-a[3])+(a[4]-a[2]))<=m || ((a[3]-a[2])+(a[3]-a[1]))<=m) cout<<3;
        else if(((a[4]-a[3])<=m) || ((a[3]-a[2])<=m)|| ((a[2]-a[1])<=m)) cout<<2;
        else cout<<1;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        q[0]=0;
        for(int i=1;i<=n;i++)
        {
            q[i]=q[i-1]+a[i];
        }
        long long ans=upper_bound(q+1,q+1+n,m)-q;
        if(ans>n) cout<<n;
        else cout<<ans;
    }
    return 0;
}
