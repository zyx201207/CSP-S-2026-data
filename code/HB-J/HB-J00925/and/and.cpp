#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000];
bool cmp(int x,int y)
{

    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        int maxn = 0;
        for(int i = 1;i <= n;i++)
        {
            maxn = max(maxn,a[i]);

        }
        cout<<maxn;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
    return 0;
}
