#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,t;
long long a[5000000];
bool A=1,B=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        t=a[2]-a[1];
        if(a[i]!=i)A=0;
        else if(a[1+i]-a[i]!=t)B=0;
    }
    if(A){
        for(int i=n-1;i>=1;i--){
            m-=i;
            ans++;
            if(m<=0)break;
        }
    }else if(B){
        for(int i=n-1;i>=1;i--){
            if(m<=0)break;
            m-=t*(n-i);
            ans++;
        }
        ans--;
    }
    else{
        if(m%2==1)ans=m/2+1;
        else ans=m/2;
    }
    printf("%lld",ans);
    return 0;
}
