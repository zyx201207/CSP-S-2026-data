#include <bits/stdc++.h>

using namespace std;
#define int long long
#define el "\n"

int n,m,ans,a[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    int h;
    if(n%2==1)h=ceil(n/2);
    else if(n%2==0)h=n/2-1;
    int mid=a[h];
    //cout<<mid<<" "<<h<<el;
    int k=upper_bound(a+1,a+n+1,mid)-a;
    int s=lower_bound(a+1,a+n+1,mid)-a;
    for(int i=s;i>=1;--i){
        a[i]+=(a[k]-a[i]);
        m-=(a[k]-a[i]);
    }
    int l=upper_bound(a+1,a+n+1,a[h])-a;
    int r=lower_bound(a+1,a+n+1,a[h])-a;
    cout<<l-r;
    return 0;
}
