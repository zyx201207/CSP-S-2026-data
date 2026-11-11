#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int d[500005];
int ans=0;
bool check(int mid,int x){
    int sum=mid*(a[x]);
    sum-=d[x-1]-d[x-1-mid];
    return sum<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        d[i]=d[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=0,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,i)&&mid<i){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,l);
    }
    cout<<ans;
    return 0;
}
