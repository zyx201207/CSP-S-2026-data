#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500120],h,b[500120];
bool cmp(int x,int y)
{
    return abs(h-x)>abs(h-y);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i = 1;i<=n;i++) cin>>a[i];
    long long s = 1;
    for(long long i = 1;i<=n;i++)
    {
        long long c = 0;
        long long u = m;
        h = a[i];
        sort(a+1,a+n+1);
        for(long long j = 1;j<=n;j++)
        {
            if(u-(a[i]-a[j])>=0 && a[i]>=a[j])
            {
                u = u-(a[i]-a[j]);
                c++;
            }
            else break;
        }
        s = max(s,c);
    }
    cout<<s;
    return 0;
}
