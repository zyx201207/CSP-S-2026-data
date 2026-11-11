#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    long long ans=0;
    for(int k=30;k>=0;k--){
        int ji=0;
        for(int i=1;i<=n;i++){
            if(((a[i]&ans)==ans)&&((a[i]>>k)&1ll)) ji++;
        }
        if(ji>=m) ans+=(1ll<<k);
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}