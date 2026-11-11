#include<iostream>
#define int long long
using namespace std;
int c,t,n,d,g[2000005],f[2000005],pre[2000005],top[2000005],las,tmp[2000005];
__int128 x[2000005];
void brute(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        int pnt=i;
        f[i]=0,g[i]=1,pre[i]=1;
        for(int j=i+1;j<=n;j++){
            while(pnt<j&&x[j]-x[pnt]>d) pnt++;
            if(j==pnt) break;
            f[j]=f[pnt]+1;
            if(f[j]!=f[j-1]) top[f[j]]=j;
            g[j]=pre[top[f[j]]-1]-pre[pnt-1];
            if(g[j]==2) cnt++;
            pre[j]=pre[j-1]+g[j];
        }
        for(int j=i;j<=n;j++) f[j]=g[j]=pre[j]=top[j]=0;
    }
    cout<<cnt<<endl;
}
void A(){
    int cnt=0,ans=0;
    int pnt=1;
    f[1]=0,g[1]=1,pre[1]=1;
    for(int j=2;j<=n;j++){
        while(pnt<j&&x[j]-x[pnt]>d) pnt++;
        if(j==pnt) break;
        f[j]=f[pnt]+1;
        if(f[j]!=f[j-1]) top[f[j]]=j;
        g[j]=pre[top[f[j]]-1]-pre[pnt-1];
        if(g[j]==2) cnt++;
        ans+=cnt;
        pre[j]=pre[j-1]+g[j];
    }
    cout<<ans<<endl;
}
void BC(){
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=lower_bound(x+1,x+n+1,x[i]+d+1)-x-1;
        if(l==i) continue;
        g[l]=g[l-1]=1;
        las=i;
        for(;l<=n;){
            int r=lower_bound(x+1,x+n+1,x[l]+d+1)-x-1;
            if(l==r) break;
            if(g[l]>2) break;
            if(g[l]==2){
                if(l-1<=las) ans+=r-l,g[r]=g[r-1]=2;
                else{
                    int p2=lower_bound(x+1,x+n+1,x[l-1]+d+1)-x;
                    ans+=r-p2+1;
                    g[r]=(p2<=r?2:3);
                    g[r-1]=(p2<=r-1?2:3);
                }
            }
            else{
                if(l-1<=las) g[r]=g[r-1]=1;
                else{
                    if(g[l-1]>=2){
                        int p2=lower_bound(x+1,x+n+1,x[l-1]+d+1)-x;
                        g[r]=(p2<=r?1:3);
                        g[r-1]=(p2<=r-1?1:3);
                    }
                    else{
                        int p2=lower_bound(x+1,x+n+1,x[l-1]+d+1)-x;
                        if(l-2<=las){
                            ans+=p2-l-1;
                            g[r]=(p2<=r?1:2);
                            g[r-1]=(p2<=r-1?1:2);
                        }
                        else{
                            int p3=lower_bound(x+1,x+n+1,x[l-2]+d+1)-x;
                            ans+=p2-p3;
                            g[r]=(p3<=r?(p2<=r?1:2):3);
                            g[r-1]=(p3<=r-1?(p2<=r-1?1:2):3);
                        }
                    }
                }
            }
            las=l;
            l=r;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>tmp[i];
        for(int i=1;i<=n;i++) x[i]=tmp[i];
        if(c>=11&&c<=12) A();
        else if(c>=13&&c<=18) BC();
        else brute();
    }
}