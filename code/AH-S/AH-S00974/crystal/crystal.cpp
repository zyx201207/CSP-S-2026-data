#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
int n;ll m,a[N],pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<=r){
            mid=l+r>>1;
            if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m) r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d",ans);
    return 0;
}