#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,a[N],j,ans,cur;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1),j=1;
    for(int i=2;i<=n;i++){
        cur+=a[i-1];
        while(a[i]*(i-j)-cur>m)
            cur-=a[j],j++;
        ans=max(ans,i-j+1);
    }cout<<ans;
}