#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],ans=-1,m,andd=-1;
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],andd&=a[i];
    sort(a+1,a+n+1,greater<int>());
    if(m==n)cout<<andd;
    else if(m==1)cout<<a[1];
    else if(m==2){for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);cout<<ans;}
    else cout<<a[m];
    return 0;
}
