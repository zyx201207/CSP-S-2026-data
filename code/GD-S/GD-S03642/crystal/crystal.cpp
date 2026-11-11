#include<bits/stdc++.h>
using namespace std;
const int N=500000;
int n,ans;
long long m,a[N+5],q[N+5];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)q[i]=q[i-1]+a[i];
    for(int i=1;i<=n;++i){
        int l=i-ans;
        while(l>=1&&a[i]*(i-l)-(q[i-1]-q[l-1])<=m)l--;
        ans=i-l;
    }
    cout<<ans;
    return 0;
}