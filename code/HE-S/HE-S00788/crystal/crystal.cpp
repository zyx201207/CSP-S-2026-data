#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll a[N],s[N];
ll n,m;
bool check(int x){
    for(int l=1;l+x-1<=n;l++){
        int r=l+x-1;
        ll sum=1ll*(x-1)*a[r]-s[r-1]+s[l-1];
        if(sum<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=5e5,res=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<res<<"\n";
    return 0;
}
