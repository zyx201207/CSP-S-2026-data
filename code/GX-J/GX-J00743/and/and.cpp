#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005],maxn = -1e9,cnt = 0;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    sort(a + 1,a + n + 1,cmp);
    for (int i = 1; i <= n; i++)
    {
        cnt = a[i];
        for (int j = i + 1; j < i + m; j++)
        {
            cnt &= a[j];
        }

        if (cnt > maxn)
        {
            maxn = cnt;
        }
    }
    cout<<maxn;
    return 0;
}
