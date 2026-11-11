#include <bits/stdc++.h>
using namespace std;
#define int long long
int to[2000010][22];
int a[2000010];
int to2[5010][5010];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c,t; cin>>c>>t;
    while (t--){
        int n,d; cin>>n>>d;
        for (int i=1; i<=n; i++){
            cin>>a[i];
        }
        int p=((11<=c&&c<=14)?10:22);
        for (int i=1; i<=n; i++){
            if (c<=10)to2[i][1]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
            else to[i][1]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
            //if (to[i][0]==i) to[i][0]=n+1;
            //cout<<to[i][1]<<" ";
        }
        //cout<<"\n";
        for (int j=2; j<(c<=10?n+1:p); j++){
            for (int i=1; i<=n; i++){
                if (c<=10) to2[i][j]=to2[to2[i][j-1]][1];
                else to[i][j]=to[to[i][j-1]][1];
            }
        }
        int ans=0;
        if (c<=10)
        for (int i=1; i<=n; i++){
            int mx=to2[i][1]-1,cmx=max(0ll,to2[i][1]-2);
            for (int j=2; j<=n; j++){
                int l=to2[i][j-1];
                int r=to2[i][j];
                mx=to2[mx][1];
                cmx=to2[cmx][1];
                //if (l!=r) cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<mx<<" "<<cmx<<"\n";
                ans+=max(0ll,mx-max(cmx,l));
                int tmp=to2[i][j]-1;
                if (tmp>mx) cmx=mx,mx=tmp;
                else cmx=max(cmx,tmp);
                int tmp2=max(0ll,to2[i][j]-2);
                cmx=max(cmx,tmp2);
            }
        }
        else
        for (int i=1; i<=n; i++){
            int mx=to[i][1]-1,cmx=max(0ll,to[i][1]-2);
            for (int j=2; j<p; j++){
                int l=to[i][j-1];
                int r=to[i][j];
                mx=to[mx][1];
                cmx=to[cmx][1];
                //if (l!=r) cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<mx<<" "<<cmx<<"\n";
                ans+=max(0ll,mx-max(cmx,l));
                int tmp=to[i][j]-1;
                if (tmp>mx) cmx=mx,mx=tmp;
                else cmx=max(cmx,tmp);
                int tmp2=max(0ll,to[i][j]-2);
                cmx=max(cmx,tmp2);
            }
        }
        cout<<ans<<"\n";
    }
}
