#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,i;
    long long s=0,ans=0;
    scanf("%d",&n);
    char c[n+1];
    long long a[n+1];
    for(i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
        s+=a[i];
        a[i]=s;
    }
    long long l=0,r=s;
    int ln=1,rn=n;
    while(ln<rn){
        if(r-l==1){
        break;
        }
        if(a[ln]-l>r-a[rn-1]){
            if(c[ln]!=c[rn]){
                ans+=r-a[rn-1];
                //printf("%lld 1 %d %d %d %d ",ans,l,r,ln,rn);
            }
            l+=r-a[rn-1];
            r-=r-a[rn-1];
            rn--;
        }
        if(a[ln]-l<r-a[rn-1]){
            if(c[ln]!=c[rn]){
                ans+=a[ln]-l;
               // printf("%lld 2 %d %d %d %d ",ans,l,r,ln,rn);
            }
            r-=a[ln]-l;
            l+=a[ln]-l;
            ln++;
        }
        if(a[ln]-l==r-a[rn-1]){
            if(c[ln]!=c[rn]){
                ans+=a[ln]-l;
                //printf("%lld 3 %d %d %d %d ",ans,l,r,ln,rn);
            }
            l+=r-a[rn-1];
            r-=r-a[rn-1];
            rn--;
            ln++;
        }
    }
    printf("%lld",ans);
    return 0;
}
