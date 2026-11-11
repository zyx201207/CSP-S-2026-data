#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
const int N1=5005;
const int M=21;
ll rd(){
    ll f=1,s=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) s=s*10+(c^48);
    return f*s;
}
int c,n;
ll d,a[N],ans;
ll mn[N],cnt[N];
int nxt[N];
// bool ok[N1][N1];int lef[N1],rig[N1];
// void init(){
//     ans=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++)
//             nxt[i][j]=0,ok[i][j]=0;
//         lef[i]=rig[i]=0;
//     }
// }
void dfs(int x,int step){
    if(mn[x]>step){
        mn[x]=step,cnt[x]=1;
        for(int i=x+1;i<=n;i++){
            if(a[i]-a[x]<=d){
                dfs(i,step+1);
            }
        }
    }
    else if(mn[x]==step) cnt[x]++;
}
void solve(){
    n=rd(),d=rd();ans=0;
    for(int i=1;i<=n;i++) a[i]=rd();

    if(n==1){ cout<<"0\n"; return;}
    if(c==11||c==12){
        ll _d=a[2]-a[1];
        ll step=d/_d;
        if(step==0){ cout<<"0\n"; return;}
        for(int i=1;i<n;i++){
            if(i%step==0) continue;
            ll sh=i%step;
            if(sh==0){ cout<<"0\n"; return;}
            if(i/step==1&&i%step==step-1) ans+=n-i;
        }
        cout<<ans<<'\n';
        return;
    }
    if(c==1||c==2){
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                mn[r]=n+1,cnt[r]=0;
            }
            dfs(l,0);
            for(int r=l;r<=n;r++)
                if(cnt[r]==2) ans++;
        }
        cout<<ans<<'\n';
        return;
    }
    if(c>=3&&c<=6){
        for(int i=1;i<=n;i++){
            nxt[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
        }
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                int step=0,x=l;
                while(x<r&&nxt[x]!=x) step++,x=nxt[x];
                if(x==r){
                    // for()
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    // if(c<=10){
    //     if(n==1){ cout<<"0\n";return;}
    //     init();
    //     for(int i=1;i<=n;i++){
    //         nxt[i][0]=i;
    //         nxt[i][1]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
    //         cerr<<nxt[i][1]<<" ";
    //     }
    //     cerr<<'\n';
    //     for(int x=2;x<=n;x++)
    //         for(int i=1;i<=n;i++)
    //             nxt[i][x]=nxt[nxt[i][x-1]][1];
        
        
    //     for(int l=n;l>=1;l--){
    //         ok[l][l]=1;
    //         if(nxt[l][1]==l) continue;
    //         int dis=0;
    //         cerr<<l<<" ";
    //         for(int r=l+1;r<=n;r++){
    //             if(nxt[r-1][1]==r-1) break;
    //             if(nxt[l][dis+1]<r) dis++;
    //             int x=nxt[l][1];
    //             cerr<<l<<" "<<r<<' '<<nxt[l][1]<<' '<<dis<<'\n';
    //             if(x>=r) ok[l][r]=1;
    //             else if(nxt[x-1][dis]<r) ok[l][r]=ok[x][r];
    //             else ok[l][r]=0;
    //         }
    //         cerr<<'\n';
    //     }

    //     cerr<<'\n';

    //     for(int l=1;l<=n;l++){
    //         for(int r=l;r<=n;r++){
    //             cerr<<l<<" "<<r<<" "<<ok[l][r]<<'\n';
    //         }
    //     }

    //     for(int l=1;l<=n;l++)
    //         for(int r=l;r<=n;r++)
    //             if(ok[l][r]){
    //                 lef[l]++,rig[r]++;
    //             }
        
    //     cout<<'\n';
    //     for(int l=1;l<=n;l++){
    //         if(nxt[l][1]==l) continue;
    //         if(nxt[l][2]!=nxt[l][1]){
    //             int x=nxt[l][1],y=nxt[l][2];
    //             for(int j=x+1;j<y;j++)
    //                 if(x-1==l||nxt[x-2][1]<j)
    //                     ans+=1ll*rig[l];
                
    //             if(x-1==l||nxt[x-2][1]<y) ans+=1ll*rig[l]*lef[y];

    //         }
    //         // cout<<l<<" "<<ans<<'\n';
    //     }

    //     cout<<ans<<'\n';

    // }

}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;c=rd(),T=rd();
    while(T--) solve();
    return 0;
}
/*
6 4
-3 0 1 2 3 4
*/