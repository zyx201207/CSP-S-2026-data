#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long a[5000005],m,tot=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        if (1ll*a[i]*(i-1)-tot<=m){
            ans=i;
        }
        else{
            break;
        }
        tot+=a[i];
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
