#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int cnt=0,sum=0,ans=1;
    for(int i=1,j=1;i<=n;i++){
        cnt++,sum+=a[i];
        while(cnt*a[i]-sum>m) cnt--,sum-=a[j],j++;
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}