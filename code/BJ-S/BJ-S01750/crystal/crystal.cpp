#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,ans[N],res=1;long long m,a[N],f[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    sort(a+1,a+n+1);
    ans[1]=1;
    f[1]=0;
    for(int i=2;i<=n;i++){
        f[i]=(a[i]-a[i-1])*(i-1)*1ll+f[i-1];
        if(f[i]<=m)ans[i]=i;
        else if(a[i]==a[i-1])ans[i]=ans[i-1]+1;
        else{
            int l=1,r=i-1;
            while(l<r){
                int mid=l+r>>1;
                if(f[i]-(mid-1)*(a[i]-a[mid])-f[mid]<=m)r=mid;
                else l=mid+1;
            }ans[i]=i-r+1;
        }res=max(res,ans[i]);
    }cout<<res;
    return 0;
}
