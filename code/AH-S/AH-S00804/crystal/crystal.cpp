#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s;
int ans=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);/*
    for(int i=2;i<=n;i++)
    {
        long long s=1,km=m;
        for(int j=i-1;j>=1;j--)
        {
            if(km>=a[i]-a[j])
            {
                s++;
                km-=a[i]-a[j];
            }
            else break;
        }
        ans=max(ans,s);
    }*/
    for(int i=2,j=1;i<=n;i++)
    {
        if(i==j) continue;
        s+=(i-j)*(a[i]-a[i-1]);
        while(s>m)
        {
            s-=a[i]-a[j];
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}
