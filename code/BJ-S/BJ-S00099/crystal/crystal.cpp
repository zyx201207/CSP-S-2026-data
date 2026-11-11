#include<bits/stdc++.h>
using namespace std;
long long a[500100],sum[500100];
long long n,m,ans;
bool check(int len,int i){
    long long sm=sum[i]-sum[i-len];
    return a[i]*len-sm<=m;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r+1)/2;
            if(check(mid,i)){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,1LL*l);
    }
    cout<<ans<<endl;
    return 0;
}