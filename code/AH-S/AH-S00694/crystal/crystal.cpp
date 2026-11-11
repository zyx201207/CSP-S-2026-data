#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],sum[N],query[N],minx=1e12,ans;
int main(){
    ios::sync_with_stdio();
    cin.tie();cout.tie();
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        minx=min(minx,a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        a[i]-=minx;
        sum[i]=sum[i-1]+a[i];
        query[i]=a[i]*(i-1)-sum[i-1];
        if(query[i]<=m)ans++;
    }
    for(int i=2;i<=n;i++){
        for(int j=i+ans;j<=n;j++){
            long long xx=(a[j]-a[i])*(j-i)-(sum[j-1]-sum[i]-(j-1-i)*a[i]);
            if(xx<=m)ans++;
            else break;
        }
        if(i+ans>n)break;
    }
    cout<<ans;
    return 0;
}
