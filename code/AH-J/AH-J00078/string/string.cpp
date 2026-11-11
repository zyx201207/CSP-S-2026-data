#include<bits/stdc++.h>
using namespace std;
long long n,len=0,ans=0;
struct Node{
    long long cnt;
    char c;
}a[200000+10];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld %c",&a[i].cnt,&a[i].c);
        len+=a[i].cnt;
    }
    long long l=0,r=len+1,li=1,ri=n,lrest=a[1].cnt,rrest=a[n].cnt;//l,r,the rest of a[l],the rest of a[r]
    while(l<r&&li<ri){
        if(a[li].c!=a[ri].c)ans+=min(lrest,rrest);
        if(lrest>rrest){
            r-=rrest;
            l+=rrest;
            lrest-=rrest;
            rrest=a[--ri].cnt;
        }else if(lrest<rrest){
            l+=lrest;
            r-=lrest;
            rrest-=lrest;
            lrest=a[++li].cnt;
        }else{
            l+=lrest;
            r-=rrest;
            lrest=a[++li].cnt;
            rrest=a[--ri].cnt;
        }
    }
    printf("%lld",ans);
    return 0;
}
