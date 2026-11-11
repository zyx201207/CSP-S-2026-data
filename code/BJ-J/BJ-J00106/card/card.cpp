#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
const long long M=300005;
long long a[N],b[N],c[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    for(long long y=1;y<=n;y++){
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        long long x=0;
        for(long long i=y;i<=n;i++){
            if(b[a[i]]==0){
                c[++x]=a[i];
            }
            else{
                b[a[i]]=0;
                long long x1=0;
                for(long long j=1;j<=x;i++){
                     if(c[j]==a[i]){
                         x1=j;
                         break;
                     }
                }
                for(long long j=x1;j<=x;j++)c[j]=0;
                x=x1;
                c[++x]=a[i];
            }
            b[a[i]]++;

        }
        for(long long i=1;i<=x;i++)ans[c[i]]++;
    }
    for(long long i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
