#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int q[200010];
int a[200010];
int cnt[200010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++) q[i]=i;
    for (int i=1;i<=n;i++)
    {
        while(a[i]==a[i+1]) i++;
        cnt[a[i]]=q[i];
    }
    for (int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
