#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n);
    int ans=1,f=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i]+1) continue;
        long long num=0;
        for(int j=i-1;j>=f;j--){
            num+=a[i]-a[j];
            if(num>m){
                ans=max(ans,i-j+1);
                f=i+1;
                break;
            }
            if(j==f&&num<=m) ans=max(ans,i-f+1);
        }
    }
    cout<<ans;
    return 0;
}
