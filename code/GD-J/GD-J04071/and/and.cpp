#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,m,a[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans{};
    for(int s=29;s>=0;s--)
    {
        int c{};
        for(int i=1;i<=n;i++)if(a[i]>>s&1)c++;
        if(c>=m)
        {
            n=remove_if(a+1,a+n+1,[=](int x){return ~x>>s&1;})-a-1;
            ans+=1<<s;
        }
    }
    cout<<ans;
    return 0;
}