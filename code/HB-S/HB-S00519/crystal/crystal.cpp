#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll a[N],s[N],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=1;
    for(int i=1;i<=n;i++){
        int l=2,r=i,res=1;
        while(l<=r){
            int mid=l+r>>1;
            if(a[i]*mid-(s[i]-s[i-mid])<=m)res=mid,l=mid+1;
            else r=mid-1;
        }ans=max(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}