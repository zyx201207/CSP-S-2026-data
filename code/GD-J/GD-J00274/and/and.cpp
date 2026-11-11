#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef char ch;
typedef string str;
const ll maxn=2e5+1;
ll n,m,a[maxn],ans,bt,pos;
bool cmp(ll a,ll b)
{
    return ((a>>bt)&1)>((b>>bt)&1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m,pos=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(bt=29;~bt;bt--)
    {
        sort(a+1,a+pos+1,cmp);
        ll np=0;
        while(np<pos&&(a[np+1]>>bt)&1) np++;
        if(np>=m) pos=np,ans+=(1ll<<bt);
    }
    cout<<ans;
}