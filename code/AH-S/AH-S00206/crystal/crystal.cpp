#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
long long l=1e18,r=-1e18,mid;
long long ans;
bool check(long long shu){
    for(long long i=l;i<=r;i++){
        int p=upper_bound(a+1,a+n+1,i)-a;
        if(p==n+1) continue;
        p--;
        long long he=0;
        int cnt=0;
        for(int j=p;j>=1;j--){
            cnt++;
            he+=i-a[p];
            if(cnt>=shu||he>m) break;
        }
        if(cnt>=shu&&he<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        r=max(r,a[i]);
        l=min(l,a[i]);
    }
    sort(a+1,a+n+1);
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
