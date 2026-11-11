#include<bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n,m,avg;
long long a[N],p[N];
bool cmp(long a,long b)
{
    return a < b;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + n + 1,cmp);
    int mid = (n + 1) / 2;
    int cnt = 1;
    for(int i = mid - 1;i >= 1 && m;i--)
    {
        if(m >= a[mid] - a[i])
        {
            m -= a[mid] - a[i];
            cnt++;
        }
        else
        {
            break;
        }
    }
    if(m == 0)
    {
        for(int i = mid + 1;i <= n;i++)
        {
            if(a[i] == a[mid])
                cnt++;
            else
                break;
        }
    }
    else
    {
        for(int i = mid + 1;i <= n && m;i++)
        {
            if(m >= cnt * (a[i] - a[mid]))
            {
                m -= cnt * (a[i] - a[mid]);
                cnt++;
            }
            else
                break;
        }
    }
    cout << cnt;
    return 0;
}
