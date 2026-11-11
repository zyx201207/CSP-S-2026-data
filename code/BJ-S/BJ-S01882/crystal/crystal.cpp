#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,ans;
ll m,a[N],d[N],s[N];
__int128 t[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) d[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+d[i];
    for(int i=1;i<=n;i++) t[i]=t[i-1]+(__int128)(i-1)*d[i];
    for(int i=1;i<=n;i++){
        int L=1,R=i,j=-1;
        while(L<=R){
            int mid=(L+R)/2;
            int k=i-mid+1;
            if(t[i]-t[i-k]-(__int128)(i-k)*(s[i]-s[i-k])<=m){
                j=mid; R=mid-1;
            }
            else L=mid+1;
        }
        int k=i-j+1;
        ans=max(ans,i-j+1);
    }
    printf("%d\n",ans);
    return 0;
}
