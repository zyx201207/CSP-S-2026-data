#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],s[N],ans;
bool cmp(int x,int y)
{
    return x<y;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    s[1]=0;
    for(int i=2;i<=n;i++)
        s[i]=s[i-1]+abs(a[i]-a[i-1]);
    for(int i=1;i<=n;i++)
    {
        if(s[i]>m)
            break;
        ans=i;
    }
    cout<<ans<<'\n';
    return 0;
}
