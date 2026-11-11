#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans;
ll m;
ll a[N],sum[N],pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1){
        cout<<1<<'\n';
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        ll x=a[i]-a[i-1];
        sum[i]=sum[i-1]+x;
        pre[i]=pre[i-1]+sum[i];
    }
    for(int i=2;i<=n;i++){
        int l=1,r=i,cur=0;
        while(l<=r){
            int mid=(l+r)/2;
            //cout<<"i:"<<i<<' '<<"cur:"<<mid<<'\n';
            //cout<<(i-mid)*sum[i]-(pre[i]-pre[mid-1])<<'\n';
            if((i-mid)*sum[i]-(pre[i-1]-pre[mid-1])<=m){
                r=mid-1;
                cur=mid;
            }
            else l=mid+1;
        }
        //cout<<i<<' '<<cur<<'\n';
        ans=max(ans,i-cur+1);
    }
    cout<<ans<<'\n';
    //cout<<ans<<'\n';
    return 0;
}