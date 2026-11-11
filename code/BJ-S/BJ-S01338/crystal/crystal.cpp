#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],s[500005];
int n,m;
bool check(int x){
    int sum,f=0;
    for(int i=x;i<=n;i++){
        sum=a[i]*x-(s[i]-s[i-x]);
        if(sum<=m) f=1;
    }
    return f;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
