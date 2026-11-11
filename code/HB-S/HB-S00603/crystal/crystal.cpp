#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    bool b=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1]&&i!=1)
        {
            b=1;
        }
    }
    if(b)
    {
        //cout<<1<<" ";
        sort(a+1,a+n+1);
    }
    long long l=1,r=n;
    long long ans=0;
    while(l<r)
    {
        long long mid=(l+r)/2;
        long long id=upper_bound(a+1,a+n+1,a[mid])-a;
        id--;
        //cout<<id<<endl;
        long long all=m,cnt=0;
        //cout<<mid<<"---";
        for(int i=id;i>=1;i--)
        {
            all-=a[id]-a[i];
            //cout<<a[mid]<<" "<<a[i]<<"   ";
            cnt++;
            if(all<0)
                break;
        }
        //cout<<cnt<<endl;
        //cout<<endl;
        if(all<0)
        {
            r=mid-1;
            ans=max(ans,cnt);
        }
        else if(all==0)
        {
            cout<<cnt;
            return 0;
        }
        else
        {
            l=mid+1;
            ans=max(ans,cnt);
        }
    }
    cout<<ans;
    return 0;
}
