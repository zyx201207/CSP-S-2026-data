#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],nd;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int now=1;
    for(int i=1;i<=n;i++){
        nd+=(i-now)*(a[i]-a[i-1]);
        while(nd>m)nd-=a[i]-a[now++];
        ans=max(ans,i-now+1);
    }
    cout<<ans;
    return 0;
}
