
#include <bits/stdc++.h>
using namespace std;
int zzz,T,a[2000005],n,m;
int f(int x,int y)
{
    int minn=0;
    for (int i=x;i<=y;i++)
    {
        int k=0;
        for (int j=i+1;j<=y;j++)
        {
            if (a[i]+m>=a[j])  k=j;
            else  break;
        }
        minn++;
        x=k;
        if (x==y)  return minn;
    }
}
int ans=0;
void dfs(int x,int y,int minn,int num)
{
    if (x==y)
    {
        if (num==minn)  ans++;
        return;
    }
    if (num>=minn)  return;
    for (int i=x;i<=y;i++)
    {
        if (a[x]+m>=a[i])
        {
            dfs(i,y,minn,num+1);
        }
        else  break;
    }
    return;
}
int main () {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> zzz >> T;
    while (T--)
    {
        cin >> n >> m;
        int xyz,c=1;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
            if (i==2)  xyz=a[i]-a[i-1];
            if (i>2 && xyz!=a[i]-a[i-1])  c=0;
        }
        if (c==1)
        {
            if ((a[n]-a[n-1])*2<=m)
            {
                int sum=0;
                for (int i=3;i<=n;i+=2)
                {
                    sum+=n-i;
                }
                cout << sum << "\n";
            }
            else
            {

                cout << 0 << "\n";
            }
            continue;
        }
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                int minn=f(i,j);
                dfs(i,j,minn,0);
                if (ans==2)  cnt++;
                ans=0;
            }
        }
        cout << cnt<< "\n";
    }
    return 0;
}
