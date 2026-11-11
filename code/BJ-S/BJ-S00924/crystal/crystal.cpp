#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[555555],qzh[555555];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
    long long l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)/2;
        bool flag=0;
        for(int i=mid;i<=n;i++){
            if(mid*a[i]-(qzh[i]-qzh[i-mid])<=m){
                flag=1;
                break;
            }
        }if(flag){
            ans=max(ans,mid);
            l=mid+1;
        }else r=mid-1;
    }cout<<ans;
    return 0;
}
