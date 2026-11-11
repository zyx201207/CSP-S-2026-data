#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,ans;
ll m,w,a[N],cf[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        cf[i]=a[i+1]-a[i];
        sum[i]=sum[i-1]+cf[i];
        ans++;
        w=ans*cf[i]+w;
        if(w>m)w=w-(sum[i]-sum[i-ans]),ans--;
    }
    ans++;
    cout<<ans;
    return 0;
}
