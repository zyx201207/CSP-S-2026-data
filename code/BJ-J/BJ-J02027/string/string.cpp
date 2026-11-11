#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
int n;
struct node
{
    int a;
    char b;
    int l,r;
};
vector<node>v;
ll L;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        v.push_back({a,b,L+1,L+a});
        L+=a;
    }
    int l=0,r=n-1;
    int sl=1,sr=L;
    ll ans=0;
    while(l<=r)
    {
        ll x=v[l].r-sl+1,y=sr-v[r].l+1;
        if(x==y)
        {
            ans+=(!(v[l].b==v[r].b))*x;
            sl+=x;
            sr-=x;
            l++,r--;
        }
        else if(x<y)
        {
            ans+=(!(v[l].b==v[r].b))*x;
            sl+=x;
            sr-=x;
            l++;
        }
        else if(x>y)
        {
            ans+=(!(v[l].b==v[r].b))*y;
            sl+=y;
            sr-=y;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
