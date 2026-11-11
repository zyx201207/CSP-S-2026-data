#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[500005];
int s[500005];
int k;
int l,r,ans;
bool work(int x){
    if(a[k]*(k-x+1)-(s[k]-s[x-1])<=m) return 1;
    else return 0;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(k=1;k<=n;k++){
        l=1,r=k;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(work(mid)){
                ans=max(ans,k-mid+1);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
    }
    cout<<ans;
    return 0;
}