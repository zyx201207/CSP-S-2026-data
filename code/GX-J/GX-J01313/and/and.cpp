#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+10];
    for (long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++) cout<<a[i]<<'\n';
    long long ans=a[1];
    for (long long i=1;i<=m;i++) ans=(ans&a[i]);
    cout<<ans<<'\n';
    //cout<<(140018 & 139814);
    return 0;
}
