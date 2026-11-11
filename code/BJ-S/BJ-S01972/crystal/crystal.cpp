#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000010],q=0;
bool check(int x){
    //cout<<x<<' ';
    unsigned long long res=0;
    for(int i=1;i<=x;i++){
        res+=a[x]-a[i];
    }
    return res<=m?true:false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
            q=a[mid];
        }
        else{
            r=mid-1;
        }
        //cout<<ans<<'\n';
    }

    cout<<ans<<'\n';
    return 0;
}
