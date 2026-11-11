#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct s
{
    ll v;
    char c;
}a[N];
int n;
ll ans;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll l=0, r=0, i=1, j=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v>>a[i].c;
        r+=a[i].v;
    }
    while(l<r)
    {
        int mn=min(a[i].v, a[j].v);
        if(a[i].c==a[j].c)
        {
            a[i].v-=mn;
            a[j].v-=mn;
        }
        else
        {
            ans+=mn;
            a[i].v-=mn;
            a[j].v-=mn;
        }
        l+=mn;
        r-=mn;
        if(a[i].v==0) i++;
        if(a[j].v==0) j--;
    }
    cout<<ans;
    return 0;
}
