#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],i,ans,l,r;
char c[2000005],lc,rc;

int main(void)
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    long long l=1,r=n,lc=c[1],rc=c[n],ln=a[1],rn=a[n];
    while(l<r){
        long long ttt=min(ln,rn);
        if(lc!=rc) ans+=ttt;
        ln-=ttt;
        rn-=ttt;
        if(ln==0){
            l++;
            lc=c[l];
            ln=a[l];
        }
        if(rn==0){
            r--;
            rc=c[r];
            rn=a[r];
        }
    }
    cout<<ans<<endl;

    return 0;
}
