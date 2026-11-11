#include<bits/stdc++.h>
using namespace std;
long long a[1000500],sum[1000500],n,m;
bool check(int len){
    for(int i=1;i<=n-len+1;i++){
        long long need=a[i+len-1]*len-(sum[i+len-1]-sum[i-1]);
        if(need<=m) return true;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    long long head=1; long long tail=n;
    long long ans=1;
    while(head<=tail){
        long long mid=(head+tail)/2;
        if(check(mid)){
            ans=mid; head=mid+1;
        }
        else tail=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
