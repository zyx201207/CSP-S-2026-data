#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n);
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long long ans=0;
    for(long long i=1;i<n;i++)
    {
        long long m1=m,x=i;
        while(m1>=(long long)(a[i]-a[x-1])&&x>0)
        {
            m1-=(long long)(a[i]-a[x-1]);
            x--;
        }
        ans=(i-x+1)>ans?(i-x+1):ans;
    }
    cout<<ans;
    return 0;
}
