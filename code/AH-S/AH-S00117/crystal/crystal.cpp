#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,pos,f;
ll m,a[500005],s[500005],maxn;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        if(s[i]>=m&&!f)
            pos=i,f=1;
    }
    int j=1;
    for(int i=pos-1;i<=n;i++)
    {
        if(a[i]*(i-j+1)-s[i]+s[j-1]<=m)
        {
            maxn=max(maxn,1ll*(i-j+1));
        }
        else
        {
            i--;
            j++;
        }
    }
    cout<<maxn;
    return 0;
}
