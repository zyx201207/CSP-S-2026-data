//GZ-S00211，卿可玥，贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out ","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    long long a[n];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long s[n][n];
    memset(s,0,sizeof(s));
    for(int r=1;r<n;r++)
    {
        int p=0;
        for(int st=0;st<n-r;st++)
        {
            int ed=st+r;
            if(s[st][ed-1]==-1)
            {
                p++;
                continue;
            }
            s[st][ed]=s[st][ed-1]+(a[ed]-a[ed-1])*r;
            if(s[st][ed]>m)
            {
                s[st][ed]=-1;
                p++;
            }
        }
        if(p==n-r)
        {
            cout<<r;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
