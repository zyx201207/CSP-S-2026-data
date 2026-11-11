#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long mid;
long long cnt = 0;
long long maxnum[500005];
void _search(long long b[],long long len,long long time)
{
    if(time != 1)
    {
        for(int i = 2;i <= n;i++)
        {
            b[i-1] = b[i];
        }
        b[n] = 0;
    }
    for(int j = len;j >= 0;j--)
    {
        for(int k = 1;k <= n;k++)
        {
            if(a[k] == len+b[1])
                maxnum[cnt]++;
        }
        cnt++;
        _search(b,len-j,time+1);
    }
}
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    _search(a,m,1);
    sort(maxnum,maxnum+cnt,cmp);
    cout << maxnum[0];
    return 0;
}