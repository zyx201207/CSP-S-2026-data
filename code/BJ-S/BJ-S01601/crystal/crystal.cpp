#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int NUM=5e5+5;

int n,ans=0;
ll m,a[NUM],sum=0;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1);

    ll k=(sum+m)/n;
    int st=lower_bound(a+1,a+n+1,k)-a;
    if(a[st]>k){
        st--;
    }
    //printf("%d ",st);
    for(int i=st;i>=1;i--){
        if(a[st]-a[i]<=m){
            m-=a[st]-a[i];
            ans++;
        }else{
            break;
        }
    }
    if(ans==st){
        for(int i=st+1;m>0&&i<=n;i++){
            if(ans*(a[i]-a[st])<=m){
                m-=ans*(a[i]-a[st]);
                ans++;
            }else{
                break;
            }
        }
    }

    printf("%d",ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
