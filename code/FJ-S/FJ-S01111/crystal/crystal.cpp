#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+3;
int n;
ll m,a[N],d[N];
bool chk(int x){
    for(int i=x;i<=n;i++)
        if(a[i]*x-d[i]+d[i-x]<=m)return 1;
    return 0;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
    int l=1,r=n;
    while(l<r){
        //cout<<l<<' '<<r<<'\n';
        int mid=(l+r+1)>>1;
        if(chk(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}