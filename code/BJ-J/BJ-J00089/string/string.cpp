#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+10;
ll n,a[maxn],ans,h,mid,len,lftA,lftB,rgtA,rgtB,cnt[maxn],totlen;
char c[maxn],_c[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld %c",cnt+i,_c+i),totlen+=cnt[i];
    for(ll i=1;i<=n;i++){
        len++;
        a[len]=cnt[i];c[len]=_c[i];
        h+=a[len];
        if(totlen%2==0){
            if(h-a[len]<=totlen/2&&h>totlen/2){
                a[len+1]=h-totlen/2;
                c[len+1]=c[len];
                a[len]+=totlen/2-h;
                mid=len;
                len++;
            }
            if(h==totlen/2)
                mid=len;
        }
        if(totlen%2==1){
            if(h==totlen/2)
                mid=len;
            else if(h==totlen/2+1){
                mid=len,a[len]--;
            }
            else if(h-a[len]==totlen/2)
                a[len]--;
            else if(h-a[len]+1<=totlen/2&&h>totlen/2+1){
                mid=len;
                a[len]=totlen/2-h+a[len]-1;
                a[len+1]=h-totlen/2;
                c[len+1]=c[len];
                len++;
            }
        }
    }
    /*
    for(ll i=1;i<=len;i++)
        printf("%lld %c\n",a[i],c[i]);
    printf("%lld %lld\n",mid,totlen);
    */
    cnt[0]=cnt[len+1]=0;
    for(ll i=1;i<=mid;i++)
        cnt[i]=cnt[i-1]+a[i];
    for(ll i=len;i>mid;i--)
        cnt[i]=cnt[i+1]+a[i];
    /*
    for(ll i=1;i<=len;i++)
        printf("%lld ",cnt[i]);
    printf("\n");
    */
    lftA=1;rgtA=len;
    lftB=0;rgtB=0;
    while(lftB<totlen/2){
        ll lenl=cnt[lftA]-lftB;
        ll lenr=cnt[rgtA]-rgtB;
        //printf("%lld %lld %lld %lld %lld %lld ",lftA,lftB,rgtA,rgtB,lenl,lenr);
        if(c[lftA]!=c[rgtA])
            ans+=min(lenl,lenr);
        if(lenl<lenr){
            //printf("A\n");
            lftB=cnt[lftA],lftA++;
            rgtB+=lenl;
        }
        else if(lenr<lenl){
            //printf("B\n");
            rgtB=cnt[rgtA],rgtA--;
            lftB+=lenr;
        }
        else{
            //printf("C\n");
            lftB=cnt[lftA],lftA++;
            rgtB=cnt[rgtA],rgtA--;
        }
    }
    printf("%lld",ans);
    return 0;
}
