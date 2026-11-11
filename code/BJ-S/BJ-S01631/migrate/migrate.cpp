#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,c,m,n,d,x[2000005];
int ans;
int p[2000005],head,tail;
struct dmh{
    int mi,cnt;
}f[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        for(int i=1;i<=n;i++){//start
            head=1,tail=0;
            f[i].cnt=1,f[i].mi=0;
            p[++tail]=i;
            for(int j=i+1;j<=n;j++){
                f[j].cnt=0;
                while(head<=tail&&x[j]-x[p[head]]>d){
                    head++;
                }
                if(head<=tail){
                    f[j].mi=f[p[head]].mi+1;
                    //f[j].cnt=f[p[head]].cnt;
                }else {
                    break;
                }
                for(int k=head;k<=tail&&f[p[k]].mi==f[p[head]].mi;k++){
                    f[j].cnt+=f[p[k]].cnt;
                }
                if(f[j].cnt==2){
                    ans++;
                    //cout<<i<<' '<<j<<' '<<f[j].mi<<' '<<x[p[head]]<<endl;
                }
                while(head<=tail&&f[p[tail]].mi>f[j].mi)tail--;
                p[++tail]=j;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
