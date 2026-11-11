#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],la[300005];
int s[300005],ans[300005],f[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[a[i]]=i;
    }
    for(int i=1;i<=m;i++) cout<<s[i]<<' ';
    return 0;
}
