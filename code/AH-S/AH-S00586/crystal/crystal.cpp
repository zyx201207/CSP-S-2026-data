#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l=0,r=1e18,dp[500005],mx=INT_MIN,mxi,fa,fb;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=i){
            fa=1;
        }
        if(i!=2&&i!=1){
            if(a[i-1]-a[i]!=a[i-2]-a[i-1]){
                fb=1;
            }
        }
    }
    r=a[n];
    long long cc=n;
    if(fa==0){
        long long ss=0,num=0;
        for(int i=1;i<=n&&ss<=m;i++){
            num++;
            ss+=i;
        }
        printf("%lld",num);
    }else if(fb==0){
        long long ss=0,num=0;
        for(int i=1;i<=n&&ss<=m;i++){
            num++;
            ss=ss+i*labs(a[1]-a[2]);
        }
        printf("%lld",num);
    }else{
        while(cc--){
            long long mid=cc+1,sum=0,num=0;
            for(int i=1;i<=n;i++){
                dp[i]=labs(mid-a[i]);
            }
            sort(dp+1,dp+1+n);
            for(int i=1;i<=n;i++){
                sum+=dp[i];
                if(sum<=m){
                    num++;
                }
            }
            if(mx>num){
                mx=num;
                mxi=cc+1;
            }
            mx=max(mx,num);
        }
        cout<<mx;
    }
    return 0;
}
