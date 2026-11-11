#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int MAXN=500005;
long long a[MAXN],cha[MAXN],sum[MAXN],ans=0;
int pan(int st,int en){
    long long need=sum[en]-sum[st-1];
    long long len=en-st+1;
    need-=len*cha[en+1];
    if (need<=m){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        cha[i]=a[n]-a[i];
        sum[i]=sum[i-1]+cha[i];
    }
    for (int i=1;i<=n;i++){
        int l=1,r=i-1;
        //cout<<i<<"\n";
        while(l<=r){
            //cout<<l<<" "<<r<<"\n";
            long long mid=(l+r)/2;
            if (pan(mid,i-1)==1){
                r=mid-1;
                ans=max(ans,i-mid+1);
            }
            else{
                l=mid+1;
            }
        }
    }
    cout<<ans;
return 0;
}
