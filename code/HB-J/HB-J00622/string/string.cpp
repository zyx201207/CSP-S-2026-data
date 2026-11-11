#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    ll Sum=0;
    for(int i=1;i<=n;++i){
        scanf("%lld %c",&a[i],&c[i]);
        Sum+=a[i];
    }
    ll ans=0;
    ll sum1=1,sum2=Sum;
    for(int i=1,j=n;i<j&&sum1<sum2;){
        if(a[i]<a[j]){
            if(c[i]!=c[j]) ans+=a[i];
            a[j]-=a[i];
            sum2-=a[i];
            sum1+=a[i];
            ++i;
        }else if(a[i]>a[j]){
            if(c[i]!=c[j]) ans+=a[j];
            a[i]-=a[j];
            sum1+=a[j];
            sum2-=a[j];
            --j;
        }else{
            if(c[i]!=c[j]) ans+=a[i];
            //a[i]=0;
            //a[j]=0;
            sum1+=a[i];
            sum2-=a[j];
            ++i;
            --j;
        }
    }
    printf("%lld",ans);
    return 0;
}
