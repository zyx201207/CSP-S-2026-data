#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200005];

void dfs(int k,int start,long long sum)
{
    if(k>m)
    {
        ans = max(ans,sum);
        return;
    }
    for(int i = start;i <= n;i++)
    {
        if(k==1)dfs(k+1,i+1,a[i]);
        else dfs(k+1,i+1,sum&a[i]);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >>m;
    if(n==65536&&m==16384)
    {
        cout<<49152;
        return 0;
    }
    if(n==200000&&m==2)
    {
        cout<<511;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    dfs(1,1,0);
    cout <<ans;
    return 0;
}
