#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],ans,summ;
int sum=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ans=1,summ=1;
    for(int l=1,r=2;r<=n;r++){
        sum+=(a[r]-a[r-1])*summ;
        summ++;
        while(sum>m)summ--,sum-=(a[r]-a[l]),l++;
        ans=max(ans,r-l+1);
        //cout<<summ<<endl;
    }cout<<ans;
    return 0;
}
