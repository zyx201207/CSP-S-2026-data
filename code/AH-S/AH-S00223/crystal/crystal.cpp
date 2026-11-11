#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],ans;
map<ll,int> vis;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);

    vis[a[n]]=1;
    ll l=1,sum=m;
    int last=n;
    for(int i=n;i>=1;i--){
        if(sum<a[n]-a[i]){
            l=i+1;
            break;
        }
        sum-=a[n]-a[i];
    }
    ans=n-l+1;
    for(int i=n-1;i>=1;i--)
        if(vis[a[i]]==0){
            vis[a[i]]=1;
            sum+=(a[last]-a[i])*(i-l+1);
            while(l-1>=1 && sum>=a[i]-a[l-1]){
                l--;
                sum-=a[i]-a[l];
            }
            ans=max(ans,i-l+1);
            last=i;
            //cerr<<l<<' '<<i<<'\n';
        }
    cout<<ans;

    return 0;
}
