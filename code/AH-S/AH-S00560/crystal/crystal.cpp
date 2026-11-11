#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cnt,max1,cnt2,vdcsl=1,dcsl,vdisl=1;
long long a[500010];
struct sj{
    long long zb,cha;
}b[500050];
bool cmp(sj x,sj y){
    return x.cha<y.cha;
}
bool cmp2(long long x,long long y){
	return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=i){
            vdisl=0;
        }
    }
    if(n<=5000){
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            b[i].zb=i;
            b[i].cha=a[i]-a[i-1];
        }
        b[1].cha=0;
        for(int i=1;i<=n;i++){
                max1=1;
                cnt2=0;
                cnt=0;
            for(int j=i+1;j<=n;j++){
                cnt+=b[j].cha*(j-i);
                cnt2++;
                if(cnt<=m){
                    max1++;
                }else{
                    break;
                }
            }
            if(max1>ans) ans=max1;
        }cout<<ans;
        return 0;
    }else{
        if(vdisl){
            for(int i=1;i<=n;i++){
                cnt+=i-1;
                if(cnt<=m){
                    ans++;
                }else{
                    cout<<ans;
                    return 0;
                }
            }
        }
        sort(a+1,a+1+n);
        dcsl=a[2]-a[1];
        for(int i=2;i<=n;i++){
            b[i].zb=i;
            b[i].cha=a[i]-a[i-1];
            if(b[i].cha!=dcsl){
                vdcsl=0;
            }
        }if(vdcsl){
            for(int i=1;i<=n;i++){
                cnt+=dcsl*(i-1);
                if(cnt<=m){
                    ans++;
                }else{
                    cout<<ans;
                    return 0;
                }
            }
        }else{
            for(int i=1;i<=n;i++){
                cnt+=b[i].cha*(i-1);
                if(cnt<=m){
                    ans++;
                }else{
                    cout<<ans;
                    return 0;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
}
