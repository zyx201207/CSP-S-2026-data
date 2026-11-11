#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
long long pre[N];
int ans;
bool check(int x,int i){
    int l=i-x+1;
    return 1ll*a[i]*x-(pre[i]-pre[l-1])<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid,i))l=mid;
            else r=mid-1;
        }
        ans=max(ans,l);
    }
    cout<<ans;
}
