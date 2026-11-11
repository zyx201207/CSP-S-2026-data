#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=1e5+5;
int n,m,q,abc1,abc2;
int a[N][M],e[N][N],b[M];
int s[N][N];
int ans;
template <class T> inline T read(T &x){
    x=0;T f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return (T)1;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(abc1);read(n);read(m);
    read(abc2);read(q);
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        int k;read(k);
        for(int j=1;j<=k;j++){
            int x;read(x);
            read(a[i][x]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            e[i][j]=INT_MAX;
            if(i==j){
                e[i][j]=0;
                continue;
            }
            for(int k=1;k<=m;k++){
                if(a[i][k]==0||a[j][k]==0) continue;
                e[i][j]=min(e[i][j],a[i][k]+a[j][k]);
                //cout<<k<<" "<<a[i][k]<<" "<<a[j][k]<<endl;
            }
            //cout<<e[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            s[i][j]=e[i][j];
        }
        s[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                s[j][k]=min(s[j][k],s[j][i]+s[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //cout<<s[i][j]<<" ";
        }
        //cout<<endl;
    }
    while(q--){
        int x,y;
        read(x);read(y);
        ans=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][x]!=0&&a[j][y]!=0){
                    ans=min(ans,s[i][j]+a[i][x]+a[j][y]);
                }
            }
        }
        cout<<ans+b[x]+b[y]<<endl;
    }
    return 0;
}
