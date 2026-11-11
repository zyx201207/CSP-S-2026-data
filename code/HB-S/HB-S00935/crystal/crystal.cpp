#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],arr[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int key=a[2]-a[1];
    bool f=1;
    for(int i=2;i<=n;i++){
        if(key!=a[i+1]-a[i]){
            f=0;
            break;}
    }
    if(f){
        int p=sqrt(m);
        int o=(p+1)*(p+2)/2;
        if(o<=m) cout<<o+1;
        else cout<<o/(p+2)*p+1;
        return 0;}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) arr[i]=arr[i-1]+a[i];
    for(int i=n;i>=2;i--){
        for(int j=i;j<=n;j++){
            if(i*a[j]+arr[j-i]-arr[j]<=m){
                cout<<i;
                return 0;}
        }
    }
    cout<<1;
    return 0;
}