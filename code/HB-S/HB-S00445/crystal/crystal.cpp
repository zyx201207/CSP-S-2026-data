#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int s[500005];
int num;
int ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1,j=1;i<=n;i++){
        num+=(i-j)*(a[i]-a[i-1]);
        while(num>m){
            num-=a[i]-a[j];
            j++;
        }
//        cout<<num<<' ';
//        cout<<'\n';
        ans=max(ans,i-j+1);
//        cout<<ans<<' '<<i<<' '<<j<<'\n';
    }
    cout<<ans;
    return 0;
}
