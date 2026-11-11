#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool ab=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=i) ab=false;
    }
    if(ab==true){
        long long ans=0,cnt=n;
        for(int i=1;i<=n-1;i++){
            ans+=i;
            if(ans>m){
                cnt=i;
                break;
            }
        }
        printf("%lld",cnt);
        return 0;
    }else{
        long long x;
        if(a[1]>a[2]) x=a[1]-a[2];
        else x=a[2]-a[1];
        long long ans=0,cnt=n;
        for(int i=1;i<=n-1;i++){
            ans+=i*x;
            if(ans>m){
                cnt=i;
                break;
            }
        }
        printf("%lld",cnt);
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
