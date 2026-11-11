#include<bits/stdc++.h>
#define ll long long
const int N=5e5+3;
ll n,m,a[N],ans,cnt[N],b[N],cntt;
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++){
        ans=i*a[i]-b[i];
        if(ans>m){
            int l=1,r=i-1;
            while(l<r){
                int mid=(l+r)/2;
                if((i-mid)*a[i]-b[i]+b[mid]<=m) r=mid;
                else l=mid+1;
            }
            cnt[i]=i-l;
        }else{
            cnt[i]=i;
        }
        cntt=max(cntt,cnt[i]);
    }
    cout<<cntt;
    return 0;
}
