#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int awy(int x,int step)
{
    if(step == n)
    {
        return x & a[step];
    }
    int maxn = -1;
    for(int i = step;i < n;i++)
    {
        maxn = max(maxn,awy(a[i],step + 1));
    }
    return maxn;
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
    sort(a + 1,a + n + 1);
    if(m == 1)
    {
        cout << a[n];
        return 0;
    }
    cout << awy(a[1],1);
    return 0;
}