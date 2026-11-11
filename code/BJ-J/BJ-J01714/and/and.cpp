
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> num(n);
    vector<long long> s(n);
    for(long long i=0;i<n;i++)
    {
        cin>>num[i];
        s[i]=num[i];
    }
    sort(s.begin(),s.end());
    long long maxn=s[n-1]&s[n-2];
    for(long long i=0;i<n;i++)
    {
        for(long long j=i;j<n-1;j++)
        {
            maxn=max(maxn&num[j+1],maxn&num[j]);
        }
    }
    cout<<maxn;
    return 0;
}
