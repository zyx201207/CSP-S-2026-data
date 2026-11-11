#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long make[500010];
long long minone=INT_MAX,maxone=-INT_MAX,maxans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxone=max(a[i],maxone);
        minone=min(a[i],minone);
    }
    sort(a+1,a+1+n);
    for(long long i=minone;i<=maxone;i++){
        long long up=upper_bound(a+1,a+1+n,i)-a+1;
        long long cur=m,ans=0;
        for(int j=up;j>=1;j--){
            if(cur>=i-a[j]&&i>=a[j]){
                cur-=(i-a[j]);
                ans++;
            }else if(cur<i-a[j]){
                break;
            }
        }
        maxans=max(maxans,ans);
    }
    cout<<maxans;
    return 0;
}
