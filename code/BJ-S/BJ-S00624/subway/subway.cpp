#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1005;
int c,n,m,d,q,w[M],k,a[505][M],cnt[505],dis[M][M];
ll t[505][M];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>k;
        cnt[i]=k;
        for(int j=1;j<=k;j++) {
            cin>>a[i][j]>>t[i][j];
        }
    }
    if(c>6&&c<12) {
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=m;j++) {
                dis[i][j]=1e9;
            }
        }
        for(int i=1;i<=n;i++) {
            if(cnt[i]>1) {
                if(t[i][1]+t[i][2]<dis[a[i][1]][a[i][2]]) {
                    dis[a[i][1]][a[i][2]]=t[i][1]+t[i][2];
                }
                if(t[i][1]+t[i][2]<dis[a[i][2]][a[i][1]]) {
                    dis[a[i][2]][a[i][1]]=t[i][1]+t[i][2];
                }
            }
        }
        for(int k=1;k<=m;k++) {
            for(int i=1;i<=m;i++) {
                for(int j=1;j<=m;j++) {
                    int tmp=dis[i][k]+dis[k][j];
                    if(tmp<dis[i][j]) {
                        dis[i][j]=tmp;
                    }
                }
            }
        }
        while(q--) {
            int l,r;
            cin>>l>>r;
            cout<<dis[l][r]+w[l]+w[r]<<'\n';
        }
    }
    else if(c<=6){
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=m;j++) {
                dis[i][j]=1e9;
            }
        }
        for(int i=1;i<=n;i++) {
            if(cnt[i]>1) {
                for(int l=1;l<=cnt[i];l++) {
                    for(int r=2;r<=cnt[i];r++) {
                        if(t[i][l]+t[i][r]<dis[a[i][l]][a[i][r]]) {
                            dis[a[i][l]][a[i][r]]=t[i][l]+t[i][r];
                        }
                        if(t[i][l]+t[i][r]<dis[a[i][r]][a[i][l]]) {
                            dis[a[i][r]][a[i][l]]=t[i][l]+t[i][r];
                        }
                    }
                }
            }
        }
        for(int k=1;k<=m;k++) {
            for(int i=1;i<=m;i++) {
                for(int j=1;j<=m;j++) {
                    int tmp=dis[i][k]+dis[k][j];
                    if(tmp<dis[i][j]) {
                        dis[i][j]=tmp;
                    }
                }
            }
        }
        while(q--) {
            int l,r;
            cin>>l>>r;
            cout<<dis[l][r]+w[l]+w[r]<<'\n';
        }
    }
    return 0;
}
