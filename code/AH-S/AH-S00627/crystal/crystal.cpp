//Oct31==Dec25?
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m;
int a[1000005];
int sum,cnt=1,mx=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=2;
    while(l<r&&r<=n+1){
        while(r<=n+1&&sum<=m){
            sum+=(a[r]-a[r-1])*cnt;
            cnt++;
            r++;
            if(sum<=m)mx=max(r-l,mx);
           // cout<<sum<<" ";
        }
        if(sum<=m){
            mx=max(mx,r-l);
        }
        sum-=(a[r-1]-a[l]);
        cnt--;
        l++;
        if(sum<=m){
            mx=max(mx,r-l);
        }
    }
    cout<<mx;
    return 0;
}
