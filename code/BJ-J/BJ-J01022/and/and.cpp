#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long listi = 0;
bool cmp(int x,int y)
{
    return x > y;
}
long long i;
bool check(int x)
{
    while(x % 2 == 0)
    {
        x /= 2;
    }
    if(x == 1)
    {

        return false;
    }
    return true;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    sort(a + 1,a + n + 1,cmp);
    for(int i = 1;i <= n;i++)
    {
        if(!check(a[i]))
        {
            continue;
        }
        ans = a[i];
        listi = i;
        break;
    }

    m--;
    for(int i = listi + 1;i <= n;i++)
    {
        if(m == 0)
        {
            break;
        }
        if((ans & a[i]) != 0)
        {

            ans &= a[i];
            m--;
        }
    }

    cout << ans << endl;
}
