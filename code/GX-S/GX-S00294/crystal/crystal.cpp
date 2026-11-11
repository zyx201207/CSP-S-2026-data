#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500100];
long long sum[500100];
long long ans;
long long minn=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    minn=a[1];
    for(int i=1;i<=n;i++){
        a[i]-=minn;
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1,j=1;i<=n;i++){
        long long mid=(i+j)>>1;
        long long cmp=a[i]*(i-j+1)-sum[i]+sum[j-1];
        while(cmp>m){
            j++;
            mid=(i+j)>>1;
            cmp=a[i]*(i-j+1)-sum[i]+sum[j-1];
        }
        if(cmp<=m){
            ans=max(ans,1LL*(i-j+1));
        }
    }
    cout<<ans<<endl;
    return 0;
}
