#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll a[N];
int n;ll m;
ll sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int all=0;
    for(int i=1;i<=n;i++){// end at i
        int l=1,r=i,mid,ans=0;
        while(l<=r){
            mid=(l+r)/2;
            if((a[i]*(i-mid+1) - (sum[i]-sum[mid-1])) <= m){
                ans=i-mid+1;
                r=mid-1;
            }else l=mid+1;
        }
        all=max(all,ans);
    }
    cout<<all;
    return 0;
}