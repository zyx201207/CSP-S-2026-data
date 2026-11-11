#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt=1,mm=m,ans=-1;
    for(int i=1;i<=n;i++){
        mm=m;
        cnt=1;
        for(int j=i-1;j>=1;j--){
            if(a[i]==a[j]||a[i]-a[j]<=mm){
                cnt++;
                mm=mm-a[i]+a[j];
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}