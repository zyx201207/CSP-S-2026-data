#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;

int n,m,ans;
int a[N],sum[N];

int getans(int i){
    int l=1,r=i;
    int v=a[i];
    while(l<r){
        int mid=l+r>>1;
        int tmp=sum[i-1]-sum[mid-1];
        if((i-mid)*v-tmp<=m)r=mid;
        else l=mid+1;
    }
    return i-l+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        ans=max(ans,getans(i));
    }
    cout<<ans<<"\n";
    return 0;
}