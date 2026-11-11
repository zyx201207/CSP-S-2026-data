#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
typedef long long ll;
int n;
ll m,a[MAXN],s,c;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=1;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n&&c*a[j]-s<=m)c++,s+=a[j],j++;
        ans=max(ans,j-i);
        c--,s-=a[i];
    }
    cout<<ans;
    return 0;
}