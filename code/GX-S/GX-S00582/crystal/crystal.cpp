#include<bits/stdc++.h>
using namespace std;
int a[500005]={0},c[1000000]={0};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,i,j,ma=0,m1=0,h=0,ans=1;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==0)
    {
        for(i=1;i<=n;i++)
        {
            c[a[i]]++;
        }
        for(i=0;i<=100001;i++)
        {
            if(c[i]>m1)
            {
                m1=c[i];
            }
        }
        cout<<m1;
        return 0;
    }
    for(i=2;i<=n;i++)
    {
        h=0;
        ans=1;
        for(j=i-1;j>=1;j--)
        {
            h=h+a[i]-a[j];
            if(h>m)
            {
                break;
            }
            ans++;
        }
        if(ans>ma)
        {
            ma=ans;
        }

    }
    cout<<ma;
    return 0;
}
