#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],s[N];
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=1,l=n-1;
    for(int i=n;i;i--){
        while(l){
            long long sum=m;
            sum=sum+s[i]-s[l-1]-a[i]*(i-l+1);
            if(sum>=0){
                l--;
            }else{
                ans=max(ans,i-l);
                break;
            }
        }
        if(!l){
            ans=max(ans,i);
            break;
        }
    }
    printf("%d\n",ans);

    return 0;
}
