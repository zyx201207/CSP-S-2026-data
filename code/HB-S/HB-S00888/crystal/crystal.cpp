#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,st = 0;
    long long m,sum = 0,sum2 = 0,m1 = 0,mmax = 0;
    cin>>n>>m;
    vector<long long> a(n);
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    if(m == 0)
    {
        long long a1[500001];
        for(int i = 0;i<n;i++)
        {
            a1[a[i]]++;
            mmax = max(mmax,a1[a[i]]);
        }
        cout<<mmax;
        return 0;
    }
    sort(a.begin(),a.end());
    vector<long long> d(n-1);
    for(int i = 0;i<n-1;i++)
    {
        d[i] = a[i+1]-a[i];
    }
    int i = 0;
    while(i<n-1)
    {
        m1++;
        sum+=d[i]*m1;
        sum2+=d[i];
        if(sum>m && d[i+1]*(m+1)<sum2)
        {
            sum-=sum2;
            sum2-=d[st];
            st++;
        }
        if(sum>m)
        {
            mmax = max(mmax,m1);
            m1 = 0;
            sum = 0;
            sum2 = 0;
            st++;
            i = st;
            continue;
        }
        i++;
        mmax = max(mmax,m1+1);
    }
    cout<<mmax;
    return 0;
}
