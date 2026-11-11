#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;

ll m;

ll a[5*100005],num[5*100005];

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    bool flag1=true,flag2=true;
    scanf("%d%lld",&n,&m);
    ll t;
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        if(i>=2 && a[i]!=a[i-1])
            flag1=false;
        if(i==2)
            t=a[2]-a[1];
        if(i>=3 && a[i-1]+t!=a[i])
            flag2=false;
    }
    if(flag1==true){
        printf("%d",n);
        return 0;
    }
    if(flag2==true){
        ll t=a[2]-a[1];
        if(t<0)
            t=-t;
        ll ans=0;
        int c;
        for(int i=1;i<=n;++i){
            ans=ans+t*i;
            if(ans>m)
                break;
            c=i;
        }
        printf("%d",c+1);
        return 0;
    }
    sort(a+1,a+n+1);
//    for(int i=1;i<=n;++i)
//        num[i]=a[i]-a[i-1];
//    num[1]=0;

    int l=0;
    for(int i=2;i<=n;++i){
        int now=l;
        while(1){
            bool flag=true;
            ll ans=0;
            now++;
            if(now>n || i-now<=0)
                break;
            for(int j=i-now;j<=i;++j){
                ans=ans+a[i]-a[j];
                if(ans>m){
                    flag=false;
                    break;
                }
            }
            if(flag==true)
                l=now;
            else
                break;
        }
    }

    printf("%lld",l+1);
    return 0;
}
