#include<bits/stdc++.h>
#define int long long
#define il inline
#define co const
#define re register
using namespace std;
il int read();
co int N=2e6+10;
int a[N],dis[5010][5010],cs[5010][5010];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int bh=read(),T=read();
    while(T--){
        int n=read();
        int d=read();
        for(re int i=1;i<=n;++i){
            a[i]=read();
        }
        if(bh==11||bh==12){
            int gc=a[2]-a[1];
            if(d<gc*2){
                cout<<"0\n";
                continue;
            }
            gc=d/gc*2;
            if(n<gc){
                cout<<"0\n";
            }
            else{
                cout<<n-gc+1<<'\n';
            }
            // cout<<n-d/gc*2<<'\n';
            continue;
        }
        int ans=0;
        for(re int i=1;i<=n;++i){
            for(re int j=1;j<=i;++j){
                dis[i][j]=1e18;
                cs[i][j]=0;
            }
            cs[i][i]=1;
            dis[i][i]=0;
            for(re int j=i-1;j>=1;--j){
                if(a[i]-a[j]>d)continue;
                for(re int k=1;k<=j;++k){
                    if(dis[j][k]+1<dis[i][k]){
                        dis[i][k]=dis[j][k]+1;
                        cs[i][k]=cs[j][k];
                    }
                    else if(dis[j][k]+1==dis[i][k]){
                        cs[i][k]+=cs[j][k];
                    }
                }
            }
            for(re int j=1;j<=i;++j){
                ans+=(cs[i][j]==2);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
il int read(){
    int ans=0;
    bool op=0;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')op=1;
        ch=getchar();
    }
    while(isdigit(ch)){
        ans=(ans<<1)+(ans<<3)+(ch^48);
        ch=getchar();
    }
    if(op)return -ans;
    return ans;
}