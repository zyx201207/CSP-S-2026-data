#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int nodes[N];
int f[N];
int a[N];
int b[N];
int c[N];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>nodes[i];
        a[nodes[i]]++;
        if(b[nodes[i]])
        {
            for(int j=b[nodes[i]];j<i;j++)
            {
                a[nodes[j]]--;
            }
            a[nodes[i]]=1;
        }
        b[nodes[i]]=i;
        memset(f,0,sizeof(f));
        for(int j=1;j<=m;j++)
        {
            if(a[j]&&f[j]==0)
            {
                f[j]=1;
                c[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<c[i]<<" ";
}
