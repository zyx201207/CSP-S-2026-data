#include<bits/stdc++.h>
using namespace std;
long long a[500015];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,c = 1;
    cin>>n>>m;
    for(long long i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(long long i = 1;i <= n;i++)
    {
        long long d = 1,e = m;
        for(long long j = i-1;j >= 1;j--)
        {
            if(e - (a[i] - a[j]) >= 0)
            {
                d++;
                e -= (a[i] - a[j]);
            }
            else
            {
                break;
            }
        }
        c = max(c,d);
    }
    cout<<c;

    return 0;
}
