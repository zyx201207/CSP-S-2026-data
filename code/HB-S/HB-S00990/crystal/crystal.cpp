#include <bits/stdc++.h>

using namespace std;
#define maxn 500005
long long a[maxn],n,m,l,r,d[maxn],ans;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    l=1;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
    for(int i=2;i<=n;i++){
        while(l<=i){
            if((i-l+1)*a[i]-(d[i]-d[l-1])<=m)break;
            else l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
