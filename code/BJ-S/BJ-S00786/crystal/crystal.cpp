#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll  a[500010],pre[500010];
ll ans=0,pos=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        while(pos<=i&&(i-pos+1)*a[i]-(pre[i]-pre[pos-1])>m)pos++;
        ans=max(ans,i-pos+1);
    }
    cout<<ans<<endl;
    return 0;
}
