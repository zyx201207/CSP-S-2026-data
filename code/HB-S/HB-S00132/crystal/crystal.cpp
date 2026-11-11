#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5e+5 + 5;

int a[MAXN],sum[MAXN];
int n, m;

bool check(int l,int r){
    return (r-l+1)*a[r]<=m+(sum[r]-sum[l-1]);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
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

    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=l+(r-l)/2;
            if(check(mid,i))
                r=mid;
            else
                l=mid+1;
        }
        ans=max(ans,i-l+1);
    }

    cout<<ans<<'\n';

    return 0;
}