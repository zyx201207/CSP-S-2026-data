#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,ans;
ll m,sum;
bool flag;
ll a[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
        if(i!=1&&d[i]!=d[i-1]) flag=1;
    }
    if(!flag){
        for(int i=d[2];;i+=d[2]){
            if(sum+i<=m&&ans<n){
                sum+=i;
                ans++;
            }
            else break;
        }
        cout << min(ans+1,n);
        return 0;
    }
    for(int i=1;i<=n;i++){
        int cst=0,cnt=0;
        for(int j=i;j>=1;j--){
            if(a[i]-a[j]+cst<=m){
                cst+=a[i]-a[j];
                cnt++;
                ans=max(ans,cnt);
            }
        }
    }
    cout << ans;
    return 0;
}
