#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAXN=5e5+5;
int a[MAXN];
int n,m;
int ans;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int ttt=a[i];
        int sum=0;
        int cnt=1;
        for(int j=i-1;j>=1;j--){
            sum+=(a[i]-a[j]);
            if(sum<=m)cnt++;
            else break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}