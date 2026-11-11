#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e6+5;

long long n,m;
long long a[maxn];
long long b[maxn];

void init()
{
    cin >> n >> m;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];   
    }
}

bool check(long long,long long);


void work()
{
    sort(a + 1,a + 1 + n);
    
    for(long long i = 1; i <= n; i++)
    {
        b[i] = a[i];
        b[i] += b[i-1];
    }

    // for(long long i = 1; i <= n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // cout << endl;

    long long ans = 0;

    for(long long i = 1; i <= n; i++)
    {
        long long l = 1;
        long long r = i;
        // cout << "start lr : ";
        // cout << l << " " << r << endl;
        while(l < r)
        {
            long long mid = (l + r) >> 1;
            if(check(mid, i))
            {
                // ans = max(ans,r);
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        // cout << "end lr : ";
        // cout << l << " " << r << endl;
        ans = max(ans,i - l + 1);
    }


    cout << ans << endl;
}

bool check(long long mid,long long nowidx)
{
    // cout << "NOW  CHECK : ";
    // cout << mid << " " << nowidx << " " << ((((nowidx - mid + 1) * a[nowidx]) - (b[nowidx] - b[mid - 1])) >= m) << endl;
    return (((nowidx - mid + 1) * a[nowidx]) - (b[nowidx] - b[mid - 1])) <= m;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    init();
    work();
    return 0;
}