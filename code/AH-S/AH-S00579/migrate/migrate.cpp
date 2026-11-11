#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int l[2000005];
int r[2000005];
int middle[2000005];
int in=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    scanf("%d%d",&c,&t);
    for(int z=1;z<=t;z++){
        in=0;
        int n;
        long long d;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n-3;i++){
            int l1=0,r1=n+1;
            while(l1+1<r1){
                int mid=(l1+r1)/2;
                if(a[mid]<=a[i]+d){
                    l1=mid;
                }else{
                    r1=mid;
                }
            }
            if(i<l1-1){
                int ll=0,rr=n+1;
                while(ll+1<rr){
                    int mid=(ll+rr)/2;
                    if(a[mid]<=a[l1-1]+d){
                        ll=mid;
                    }else{
                        rr=mid;
                    }
                }
                if(a[ll]-a[i]>d && a[ll]-a[l1-2]>d){
                    l[++in]=i;
                    r[in]=ll;
                    middle[in]=l1-1;
                }
            }
        }
        middle[0]=1;
        middle[in+1]=n;
        long long ans=0;
        for(int i=1;i<=in;i++){
            int le=l[i];
            int ri=r[i];
            int left=1;
            int right=1;
            while(le> middle[i-1]){
                if(a[le]-a[le-1]<=d){
                    le--;
                    left++;
                }else{
                    break;
                }
            }
            while(ri< middle[i+1]){
                if(a[ri+1]-a[ri]<=d){
                    ri++;
                    right++;
                }else{
                    break;
                }
            }
            ans+=left*right;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
