//GZ-S00263 兴义市弘毅中学 韩愈信
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],b[500005],tmp,ans;
bool check(int num){
    return (num*a[tmp]-(b[tmp]-b[tmp-num])<=m);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
        tmp=i;
        int l=1,r=i,mid,sum=0;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)){
                l=mid+1;
                sum=max(sum,mid);
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
