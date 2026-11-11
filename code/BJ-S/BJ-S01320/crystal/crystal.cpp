#include <bits/stdc++.h>
using namespace std;
long long c[500005],s[500005],sum[500005],cha[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,maxn = -1e9;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    long long minn = c[1];
    if(minn<0)
    {
        int dis = abs(c[1]);
        for(int i = 1;i<=n;i++)
        {
            c[i] += dis;
        }
    }
    sort(c+1,c+n+1);
    for(int i = 1;i<=n;i++)
    {
        s[i] = c[i]-1;
        cha[i] = c[i] - c[i-1];
        sum[i] = sum[i-1]+(c[i]-c[i-1])*(i-1);
    }
    long long t = 0;
    for(int i = 2;i<n;i++)
    {
        long long l = i,r = n;
        while(l<=r)
        {
            long long mid = (l+r)/2,M;
            if(t==0||s[mid]+s[mid]-t+1<0)    M=m;
            else M = m+(s[mid]+s[mid]-t+1)*t/2;
            if(sum[mid]>M)
                r = mid-1;
            else
                l = mid+1;
        }
        t++;
        l--;
        l -= i-2;
        maxn = max(maxn,l);
    }
    cout<<maxn;
    return 0;
}
