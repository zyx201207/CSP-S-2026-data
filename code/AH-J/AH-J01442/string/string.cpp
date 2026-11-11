#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=200010;
LL a[N],g[N];
char c[N],st[N];
bool pd;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL n;
    cin>>n;
    LL sum=0;
    for(LL i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    LL l,r;
    if(sum%2==0){l=sum/2,r=sum/2+1;}
    else{l=sum/2,r=sum/2+2;}
    LL lt,rt,k=0,cnt=0;
    for(LL i=1;i<=n;i++){
        cnt+=a[i];
        if(!pd){
            if(cnt==l){
                lt=i,rt=i+1;
                g[++k]=a[i];
                st[k]=c[i];
                if(r-l==2){a[i+1]--;}
                pd=true;
            }
            else if(cnt>l){
                lt=i,rt=i+1;
                g[++k]=a[i]-cnt+l;
                st[k]=c[i];
                g[++k]=cnt-l;
                if(r-l==2){
                    if(g[k]==1){st[k]=c[i+1];}
                    else{st[k]=c[i];}
                }
                else{st[k]=c[i];}
                pd=true;
            }
            else{
                g[++k]=a[i];
                st[k]=c[i];
            }
        }
        else{
            g[++k]=a[i];
            st[k]=c[i];
        }
    }
    LL ans=0;
    while(lt>=1||rt<=k){
        if(g[lt]>g[rt]){
            if(st[lt]!=st[rt]){ans+=g[rt];}
            g[lt]-=g[rt],g[rt]=0;
            rt++;
        }
        else if(g[lt]<g[rt]){
            if(st[lt]!=st[rt]){ans+=g[lt];}
            g[rt]-=g[lt],g[lt]=0;
            lt--;
        }
        else{
            if(st[lt]!=st[rt]){ans+=g[lt];}
            g[lt]=g[rt]=0;
            lt--,rt++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
