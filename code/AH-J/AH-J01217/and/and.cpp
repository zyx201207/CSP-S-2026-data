#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],f[N],ans;
bool sy[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(m==1) {cout<<a[n];return 0;}
    if(m==n){
        ans=a[1];
        for(int i=1;i<=n;i++)ans &=a[i];
        cout<<ans;
        return 0;
    }
    cout<<a[n-m+1];
    return 0;
}
