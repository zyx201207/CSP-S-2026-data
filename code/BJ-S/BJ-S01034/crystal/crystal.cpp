#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[500010],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        if(a[i]*(i-1)-sum[i-1]<=m)ans++;
        else break;
    }
    cout<<ans;
    return 0;
}
