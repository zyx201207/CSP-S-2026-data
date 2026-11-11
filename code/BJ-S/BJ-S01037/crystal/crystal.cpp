#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500005;

int n,a[maxn],m,cha[maxn],ans;
bool check(int x){
    int sum=0,minn=1e18;
    for(int i=1;i<=n-x+1;i++){
        sum=0;
        for(int j=i+1,cnt=1;j<=i+x-1;j++,cnt++){
            sum+=cha[j]*cnt;
        }
        minn=min(minn,sum);
    }
    if(minn<=m) return true;
    return false;

}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        cha[i]=a[i]-a[i-1];
    }
    int l=0,r=n,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
