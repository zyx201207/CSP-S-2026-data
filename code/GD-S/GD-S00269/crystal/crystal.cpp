#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int a[500005];
int sum[500005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int res=0;
    for(int i=1;i<=n;i++){
        int l=i,r=n,ans=0;
        while(l<=r){
            int mid=l+r>>1;
            if(a[mid]*(mid-i+1)-sum[mid]+sum[i-1]<=m){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        res=max(res,ans-i+1);
    }
    cout<<res<<endl;
    return 0;
}
//100