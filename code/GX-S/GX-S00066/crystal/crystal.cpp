#include<bits/stdc++.h>
using namespace std;
const int N=500009;
long long n,m,a[N],c[N],sum[N],cnt[N],s[N],b[N];
int ans;
int check(int l,int r){
    int id=r;
    long long t=sum[r];
    while(l<=r){
        int mid=(l+r)/2;
        if(t-sum[mid-1]<=m){
            id=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return id;
}
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
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i==1)c[i]=0;
        else c[i]=a[i]-a[i-1];
        sum[i]=sum[i-1]+c[i]*(i-1);
    }
    for(int i=1;i<=n;i++){
        int id=check(1,i);
        ans=max(ans,i-id+1);
    }
    cout<<ans;
    return 0;
}
