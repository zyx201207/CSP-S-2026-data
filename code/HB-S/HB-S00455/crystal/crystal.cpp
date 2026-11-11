#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll s[N];
int n;
ll m;
bool check(int op)
{
    ll sum=m;
    int pos=op-1;
    while(pos>=1)
    {
        if(sum>=(s[op]-s[pos])) 
        {
            sum-=(s[op]-s[pos]);
            pos--;
        }
        else break;
    }
    if(pos<1) return true;
    else return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+n+1);
    int l=1,r=n;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}