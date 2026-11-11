#include<bits/stdc++.h>
using namespace std;
long long m,n,a[600005];
long long nw,l,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    l=1;nw=0;
    sort(a+1,a+1+n);
    for(long long i=2;i<=n;i++){
        nw+=l*(a[i]-a[i-1]);
        if(nw<=m){
            l++;
            ans=max(l,ans);
        }
        else{
            while(nw>m){
                nw-=a[i]-a[i-l];
                l--;
            }
            l++;
        }
    }
    printf("%lld",ans);
    return 0;
}