#include<bits/stdc++.h>
using namespace std;
long long n,m,ans = 0;
long long a[100100];
long long h[100100];
struct node
{
    long long x;
    int i1,i2;
}c[100100];
long long p = 1073741824;
bool cmp(node x,node y)
{
    return x.x < y.x;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int ij = 1; ij <= 30; ij++)
    {
        for(int i = 1; i <= n; i++)
        {
            h[i] = a[i] % p;
        }
        sort(h + 1,h + n + 1);
        for(int i = 1; i <= n; i++)
        {
            c[i].x = h[i] - h[i - 1];
            c[i].i1 = i - 1;
            c[i].i2 = i;
        }
        sort(c + 1,c + n + 1,cmp);
        long long sum = p - 1;
        for(int i = 1; i < m; i++)
        {
            sum &= h[c[i].i1];
            sum &= h[c[i].i2];
        }
        ans = max(ans,sum);
        p /= 2;
    }
    cout << ans;
    return 0;
}
//Trick||Treat!
