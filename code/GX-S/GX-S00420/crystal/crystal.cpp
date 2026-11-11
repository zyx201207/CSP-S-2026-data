#include <bits/stdc++.h>
using namespace std;
long long ans,n,m,leg,dk,gc,pd;
long long a[500005],d[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]+=1000000000001;
    }
    gc=a[1]-a[0];
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
        d[i]=a[i]-a[i-1];
        if(d[i] == gc) pd++;
    }
    if(pd != n-1)
    {
        for(int i=1;i<n;i++)
        {
            leg=ans=0;
            for(int j=i;j<n;j++)
            {
                leg+=d[j]*(j-i+1);
                if(leg > m)
                {
                    ans=j-i+1;
                    break;
                }
            }
            if(ans >= dk) dk=ans;
        }
        cout<<dk;
        return 0;
    }else{
        int i=1;
        while(m >= 0)
        {
            m-=i*gc;
            i++;
        }
        cout<<i-1;
        return 0;
    }
}
