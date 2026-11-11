#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m;
const int MAXN=5e5+10;
LL a[MAXN];
int l;
LL need;
int ans;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int r=1;r<=n;r++)
    {
        need=need+(a[r]-a[r-1])*(r-l);
        while(need>m)
        {
            need-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
