#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N],d[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    // for(int i=2;i<=n;i++)d[i]=a[i]-a[i-1];
    int l=1,cnt=a[2]-a[1];
    for(int i=2;i<=n;i++){
        while(l<=i&&cnt>m){
            l++;
            cnt-=a[i]-a[l];
        }
        ans=max(ans,i-l+1);
        cnt+=(a[i+1]-a[i])*(i-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}