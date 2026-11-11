#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5,inf=0x3f3f3f3f;
int n,d,c,t;
int a[maxn];
// void dfs(int u)
// {
//     if(u==)
// }
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        fill(a+1,a+n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int cnt=0;
        // dfs(1);
        cout<<cnt<<endl;
    }
    return 0;
}