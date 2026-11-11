#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],b[300005],k;
map<ll,ll> ans;vector<ll> v;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;v.resize(m+3);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
        if(b[a[i]]){
            for(int j=b[a[i]];j<k;j++) b[v[j]]=0;
            k=b[a[i]];
        }
        else v[k]=a[i],b[a[i]]=++k;
        for(int j=0;j<k;j++) ans[v[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
