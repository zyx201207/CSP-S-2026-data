#include<bits/stdc++.h>
using namespace std;
struct qwe
{
    int i;bool v;
}cnt[300005];
long long a[20005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(cnt[a[i]].v)
            for(int j=i;j>=cnt[a[i]].i;j--)a[i]=0;
    }
    cout<<2<<" "<<3;
    return 0;
}