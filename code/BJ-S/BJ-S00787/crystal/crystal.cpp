#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long bs(long long l,long long r,long long k){
    long long mid=l/2+r/2,ans=0;
    while(l<=r){
        long long mid=l/2+r/2;
        //if(mid>=(1ll<<61)){r=mid-1;continue;}
        if(mid/2ll*(mid+1)==k){
            return mid;
        }
        if(mid/2ll*(mid+1)<k){
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>2&&flag){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag=0;
        }
    }
    if(flag){
        long long cha=a[2]-a[1];
        m/=abs(cha);
        cout<<bs(0,n,m)+1;
        return 0;
    }
    sort(a+1,a+n+1);
    unsigned long long chas=0;
    for(int i=1;i<n;i++)chas+=a[n]-a[i];
    if(chas<=m){
        cout<<n;
        return 0;
    }
        int maxn=1;
        for(int i=n;i>1;i--){
            long long cnt=0;
            int ans=1;
            for(int j=1;j<i;j++){
                cnt+=a[i]-a[j];
                if(cnt>m)break;
                ans++;
            }
            maxn=max(maxn,ans);
        }
        cout<<maxn;
    return 0;
}
