#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long len=0;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cin>>c[i];
        len+=a[i];
    }
    int li=1,ri=n;
    char lc=c[1],rc=c[n];
    long long l1=1,r1=a[1];
    long long r2=len,l2=len-a[n]+1;
    while(li<ri){
        //cout<<li<<" "<<ri<<" "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
        long long rr,ll,rrr,lll;
        if(r1-1>len-l2){
            rr=len-(r1-1+1)+1;
            ll=len-(l1-1+1)+1;
            lll=max(l2,rr);
            rrr=min(r2,ll);
            if(lc!=rc)ans+=(rrr-lll+1);
            l1=1+(len-l2+1)-1+1;
            ri--;
            rc=c[ri];
            r2=l2-1;
            l2=r2-a[ri]+1;
        }
        else if(r1-1<len-l2){
            rr=1+(len-r2+1)-1;
            ll=1+(len-l2+1)-1;
            //cout<<ll<<"*"<<rr<<endl;
            lll=max(l1,rr);
            rrr=min(r1,ll);
            if(lc!=rc)ans+=(rrr-lll+1);
            r2=len-(r1-1+1)+1-1;
            li++;
            lc=c[li];
            l1=r1+1;
            r1=l1+a[li]-1;
        }
        else{
            rr=1+(len-r2+1)-1;
            ll=1+(len-l2+1)-1;
            lll=max(l1,rr);
            rrr=min(r1,ll);
            if(lc!=rc)ans+=(rrr-lll+1);
            li++;
            lc=c[li];
            l1=r1+1;
            r1=l1+a[li]-1;
            ri--;
            rc=c[ri];
            r2=l2-1;
            l2=r2-a[ri]+1;
        }
        //cout<<rrr-lll+1<<endl;
    }
    printf("%lld",ans);
    return 0;
}
