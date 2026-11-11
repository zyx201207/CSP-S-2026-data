#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
bool flag=1;
long long ans=-1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(int(log2(a[i]+1))!=log2(a[i]+1)) flag=0;
    }
    sort(a+1,a+n+1,greater<int>());
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++) if(a[i]&a[j]>ans) ans=a[i]&a[j];
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++) ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    if(flag) cout<<a[m];
    return 0;
}