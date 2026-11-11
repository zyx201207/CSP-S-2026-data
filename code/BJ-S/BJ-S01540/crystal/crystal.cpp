#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;
int n,m,a[maxn];
int s[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)s[i+1]=s[i]+a[i];
    int ans=1;
    for(int i=0;i<n;i++){
        int l=1,r=i+1;
        while(l<=r){
            int mid=l+r>>1;
            int tmp=1ll*mid*a[i]-(s[i+1]-s[i+1-mid]);
            if(tmp<=m){
                ans=max(ans,mid);
                l=mid+1;
            }else r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
//椰子糕真好吃咕咕嘎嘎
//突然就get到了这种食物OMG