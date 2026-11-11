#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005],dis[500005];

bool check(int t){
    for(int i=t;i<=n;i++){
        int sum=dis[i]-dis[i-t];
        if(sum+m>=a[i]*t){
            return 1;
        }
    }
    return 0;
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
        dis[i]=dis[i-1]+a[i];
    }
    int l=0,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
