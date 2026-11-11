#include <bits/stdc++.h>

using namespace std;

int n,m,a[200005],mx=-1;

void DFS(int step,int sum,int p)
{
    if(step>m)
    {
        mx=max(mx,sum);
        return;
    }
    if(sum<mx) return;
    for(int i=p+1; i<=n; i++)
    {
        DFS(step+1,sum&a[i],i);
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    if(m==1)
    {
        int mx=-1;
        for(int i=1; i<=n; i++) mx=max(mx,a[i]);
        cout << mx;
        return 0;
    }
    else if(m==2)
    {
        int mx=-1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j) continue;
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout << mx;
        return 0;
    }
    else if(m==n)
    {
        int mx=a[1];
        for(int i=2; i<=n; i++) mx&=a[i];
        cout << mx;
        return 0;
    }
    DFS(1,INT_MAX,0);
    cout << mx;
    return 0;
}
