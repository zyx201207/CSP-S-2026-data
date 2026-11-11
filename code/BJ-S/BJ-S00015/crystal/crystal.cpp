#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+10;
int n,ans;
ll m,a[N],sum[N];

int find(int x){
    int res=x;
    int l=1,r=x;
    while(l<=r){
        int mid=(l+r)/2;
        if((x-mid+1)*1ll*a[x]-(sum[x]-sum[mid-1])<=m){
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return res;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,i-find(i)+1);
    }
    cout<<ans;
}
