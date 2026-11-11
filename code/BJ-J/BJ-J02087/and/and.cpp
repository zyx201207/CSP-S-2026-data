#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200007];
char c[200007];
map<char,vector<int>> mp;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            mx=max(mx,a[i]&a[j]);
        }
    }
    cout<<mx;
    return 0;
}
