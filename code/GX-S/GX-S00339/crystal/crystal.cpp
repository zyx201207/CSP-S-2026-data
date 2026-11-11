#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,s[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++)
        cin >>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    long long left=1,right=n,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        int need=s[mid];
        for(int i=mid+1;i<=n;i++)
        {
            if(need<=m)
                break;
            need=need-(a[i-1]-a[i-mid-1])+(mid-1)*(a[i]-a[i-1]);
        }
        if(need<=m)
            left=mid+1;
        else
            right=mid-1;
    }
    cout<<right;
    return 0;
}
