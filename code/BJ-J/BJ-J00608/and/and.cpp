#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,cnt,amax=0,xa[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        amax=max(amax,a[i]);
    }
    if(m==1)
    {
        cout<<amax;
        return 0;
    }
    if(n==m)
    {
        cnt=a[1];
        for(int i=1;i<=n;i++)
        {
            cnt==cnt&a[i];
        }
        cout<<cnt;
        return 0;
    }
    if(m==2){
        amax=0;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                amax=max(amax,a[i]&a[j]);
            }
        }
        cout<<amax;
        return 0;
    }
    if(m==3){
        amax=0;
        for(int i=1;i<=n-2;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    amax=max(amax,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<amax;
        return 0;
    }
    if(m==n-1){
        amax=0;
        for(int j=1;j<=n;j++)
        {
            cnt=a[1];
            for(int i=1;i<=n;i++)
            {
                if(i!=j)cnt==cnt&a[i];
            }
            amax=max(amax,cnt);
        }

        cout<<amax;
        return 0;
    }
    return 0;
}
