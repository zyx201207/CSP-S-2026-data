#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int sum=0;
    for(int i=1,j=1;i<=n;i++){
        sum+=a[i];
        int k=a[i]*(i-j+1)-sum;
        while(k>m){
            sum-=a[j];
            k-=(a[i]-a[j]);
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
