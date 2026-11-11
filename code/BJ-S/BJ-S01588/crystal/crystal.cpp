#include<bits/stdc++.h>
using namespace std;
long long a[500009],n,m,cnt;
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        long long k=m,ans=1;
        for(int j=i-1;j>0;j--){
            if(a[i]-a[i-j]<=k)k-=a[i]-a[i-j],ans++;
        }
        cnt=max(cnt,ans);
    }
    cout<<cnt;
    return 0;
}
