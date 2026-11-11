#include <bits/stdc++.h>
using namespace std;
long long int a[500005];
long long int v[6000005];
long long int ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int n,m;
    long long int zoi=0;
    cin >>n>>m;
    for (int i =1;i<=n;i++)
    {
        cin >>a[i];
        zoi += abs(a[i]);
    }
    sort(a+1,a+n+1);
    int z=1;
    for (int i=1;i<=n;i++)
    {
        for (int j = i+1;j<=n;j++)
        {
            v[z] = a[j]-a[i];
            z++;
        }
    }
    sort(v+1,v+z);
    long long int zong=0;
    for (int i = 1;i<=z;i++)
    {
        //cout <<v[i]<<" ";
        if (zong >=m)
        {
            break;
        }
        zong+=v[i];
        ans++;
    }
    cout <<ans;
}
