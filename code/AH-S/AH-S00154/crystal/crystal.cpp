#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans,sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    long long t=n;
    for(long long i=n;i>=1;i--){
        if(i!=n) sum-=(i+1-t)*(a[i+1]-a[i]);
        while(t--){
            sum+=a[i]-a[t];
            if(sum>m) break;
        }
        //cout<<sum<<" "<<t<<" "<<i<<endl;
        sum-=a[i]-a[t];
        t++;
        ans=max(ans,i-t+1);
        if(t==1) break;
    }
    cout<<ans;
    return 0;
}
