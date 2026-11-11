#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long mem,l,r;
    char c;
}a[999999],stableSMP[9999999];
int n,sum=0,mid,anosum=0,la,ra,fl[999999],fr[999999],fll,frr;
long long L0L=0,mi=1,ma,ans=0;
char cc;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    a[1].l=1;
    stableSMP[1].l=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&stableSMP[++anosum].mem);
        scanf("%c%c",&cc,&stableSMP[anosum].c);
        //printf("[Logs]%lld %d\n",stableSMP[anosum].mem,stableSMP[anosum].c);
        L0L+=(long long)stableSMP[anosum].mem;
        stableSMP[anosum].r=stableSMP[anosum].l+stableSMP[anosum].mem-1LL;
        stableSMP[anosum+1].l=stableSMP[anosum].r+1;
        if(stableSMP[anosum].c==stableSMP[anosum-1].c){
            anosum--;
            stableSMP[anosum].mem+=stableSMP[anosum+1].mem;
            stableSMP[anosum].r+=stableSMP[anosum+1].mem;
            stableSMP[anosum+1].l=stableSMP[anosum].r+1;
        }
    }
    ma=L0L;
    long long MI_D=L0L/2+1;
    if(L0L%2LL==1){
        for(int i=1;i<=anosum;i++){
            if(stableSMP[i].l<=MI_D && stableSMP[i].r>MI_D){
                a[++sum].l=stableSMP[i].l,a[sum].r=MI_D,a[sum].mem=a[sum].r-a[sum].l+1LL,a[sum].c=stableSMP[i].c;
                a[++sum].l=MI_D+1,a[sum].r=stableSMP[i].r,a[sum].mem=a[sum].r-a[sum].l+1LL,a[sum].c=stableSMP[i].c;
                la=sum-1,ra=sum;
            }else{
                a[++sum].l=stableSMP[i].l,a[sum].r=stableSMP[i].r,a[sum].mem=stableSMP[i].mem,a[sum].c=stableSMP[i].c;
                if(a[sum].r==MI_D)
                    la=sum,ra=sum+1;
            }
        }
    }else{
        for(int i=1;i<=anosum;i++){
            if(stableSMP[i].l<MI_D && stableSMP[i].r>=MI_D){
                a[++sum].l=stableSMP[i].l,a[sum].r=MI_D-1,a[sum].mem=a[sum].r-a[sum].l+1LL,a[sum].c=stableSMP[i].c;
                a[++sum].l=MI_D,a[sum].r=stableSMP[i].r,a[sum].mem=a[sum].r-a[sum].l+1LL,a[sum].c=stableSMP[i].c;
                la=sum-1,ra=sum;
            }else{
                a[++sum].l=stableSMP[i].l,a[sum].r=stableSMP[i].r,a[sum].mem=stableSMP[i].mem,a[sum].c=stableSMP[i].c;
                if(a[sum].r==MI_D-1)
                    la=sum,ra=sum+1;
            }
        }
    }
    for(int i=1;i<=la;i++) fl[i]=i;
    int num=0;
    for(int i=sum;i>=ra;i--) fr[++num]=i;
    fll=1,frr=1;
    //printf("[Test]sum=%d,anosum=%d\n",sum,anosum);
    for(int i=1;i<=anosum;i++){
        //printf("[Test%d]%d %lld %lld %lld\n",i,stableSMP[i].c,stableSMP[i].l,stableSMP[i].r,stableSMP[i].mem);
    }
    while(fll<=la && frr<=num){
        if(a[fr[frr]].c!=a[fl[fll]].c)
            ans+=min(a[fr[frr]].mem,a[fl[fll]].mem);
        long long ls=min(a[fr[frr]].mem,a[fl[fll]].mem);
        a[fr[frr]].mem-=ls;
        if(!a[fr[frr]].mem) frr++;
        a[fl[fll]].mem-=ls;
        if(!a[fl[fll]].mem) fll++;
        ma-=ls;
        mi+=ls;
    }
    printf("%lld\n",ans);
}
//maybe 60pts
