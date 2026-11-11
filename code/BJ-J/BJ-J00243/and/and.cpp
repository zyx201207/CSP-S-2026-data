#include<bits/stdc++.h>
using namespace std;
const int M=1e5*2+20;
long long a[M];

int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,maxn=-INT_MAX;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        if(maxn>=a[i])
        {
            continue;
        }
        if(n-i+1<m)
        {
            break;
        }
        long long cnt=0;
        priority_queue<long long> pq;
        for(long long j=1;j<=n;j++)
        {
            if(j==i)
            {
                continue;
            }
            if(cnt==m-1)
            {
                long long gj=a[j]&a[i];
                if(pq.top()<gj)
                {
                    pq.pop();
                    pq.push(gj);
                }
            }
            else
            {
                cnt++;
                int gj=a[j]&a[i];
                pq.push(gj);
            }
            if(pq.top()==a[i])
            {
                break;
            }
        }
        if(!pq.empty())
        {
            maxn=max(pq.top(),maxn);
        }

    }
    cout<<maxn;
    return 0;
}
