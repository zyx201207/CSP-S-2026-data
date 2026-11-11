#include <bits/stdc++.h>
using namespace std;

int path1(int o,int n,int d,int x[10^5+1][2*10^6+1],int t)
{
    int o0=o,cnt=0;
    for(int j=1;j<=n;j++)
        {
            if(d<x[t][j]-x[t][o0])
            {
                cnt++;
                o0=j-1;
            }
        }
    return cnt;
}
int path2(int o,int n,int d,int x[10^5+1][2*10^6+1],int t)
{
    int o0=o,cnt=1;
    for(int j=2;j<=n;j++)
        {
            if(d<x[t][j]-x[t][o0])
            {
                cnt++;
                o0=j-1;
            }
        }
    return cnt;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin >> c >> t;

    int n[t+1],d[t+1];
    int x[t+1][2*10^6+1];
    for(int i=1;i<=t;i++)
    {
        cin >> n[i] >> d[i];
        for(int j=1;j<=n[i];j++)
        {
            cin >> x[i][j];
        }
    }

    int cnt=0;

    for(int i=1;i<=t;i++)
    {
        if(path1(0,n[i],d[i],x,i)==path2(0,n[i],d[i],x,i))
        {
            cnt++;
        }
        cout << cnt << endl;

    }

    return 0;
}
