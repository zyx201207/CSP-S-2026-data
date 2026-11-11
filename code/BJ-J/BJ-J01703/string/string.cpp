#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,sum,num,mid,qzh[200005],l=1;
int newa[200005],newb[200005],qqzh[200005];
int ans,bok;
int farl,farr,karl,karr;
char b[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
        qzh[i]=qzh[i-1]+a[i];
        cin>>b[i];
    }
    mid=(sum+1)>>1;
    for(int i=n;qzh[i]>mid;i--){
        newa[++num]=a[i];
        newb[num]=b[i];
    }
    for(int i=1;i<=num;i++){
        qqzh[i]=qqzh[i-1]+newa[i];
        while(qzh[l]<=qqzh[i-1])l++;
        while(qqzh[i]>=qzh[l-1]+1){
            if(qzh[l-1]+1>=mid)break;
            farl=qzh[l-1]+1;
            farr=qzh[l];
            karl=qqzh[i-1]+1;
            karr=qqzh[i];
            if(b[l]!=newb[i]){
                //cout<<i<<' '<<l<<' '<<farr<<' '<<karr<<' '<<farl<<' '<<karl<<endl;
                ans+=(min(farr,karr)-max(farl,karl)+1);
            }
            if(qzh[l]<=qqzh[i])l++;
            else break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
3
2 a
2 b
1 c
*/
