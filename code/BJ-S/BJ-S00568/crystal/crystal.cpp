#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,i,j;
long long m,a[maxn],ans=1,d[maxn],sum[maxn],w,cnt;
bool f=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    if(n==1){
        cout<<1;
        return 0;
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
        sum[i]=d[i]+sum[i-1];
        if((i>=2)&&(d[i]!=d[i-1]))f=0;
    }
    if(f){
        i=n;
        for(j=(i-1);j>=1;j--){
            m-=(sum[i]-sum[j]);
            if(m<0)break;
            ans++;
        }
        cout<<ans;
        return 0;
    }
    for(i=2;i<=n;i++){
        w=m,cnt=1;
        for(j=(i-1);j>=1;j--){
            w-=(sum[i]-sum[j]);
            if(w<0)break;
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}