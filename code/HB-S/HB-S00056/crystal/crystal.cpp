#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans=1;
int p;
int a[500005], c[500005];
bool check(){
    for(int i=2;i<=n;i++)
        if(a[i]-a[i-1]!=p)
            return false;
    return true;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    p=a[2]-a[1];
    if(check()){
        int x=0;
        for(int i=1;i<=n;i++){
            x+=p*i;
            if(x>m){
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        c[i]=c[i-1]+a[i];
    for(int i=n;i>=2;i--){
        if(ans>i) break;
        for(int j=1;j<=i-ans+1;j++){
            int t=a[i]*(i-j)-(c[i-1]-c[j-1]);
            if(t<=m){
                ans=i-j+1;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
