#include<bits/stdc++.h>
#define ll long long

using namespace std;

int c,t,n;
ll d,x[2000005],f[5005][5005],g[5005][5005];

ll sol(){
    memset(f,0x3f,sizeof f);
    memset(g,0,sizeof g);
    for(int i = 1;i<=n;i++){
        f[i][i]=0,g[i][i]=1;
        for(int j = i+1;j<=n;j++){
            if(x[j]-x[i]<=d) f[i][j]=g[i][j]=1;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==j) continue;
            for(int k = 1;k<=n;k++){
                if(i==k||j==k) continue;
                if(f[i][j]>f[i][k]+f[k][j]){
                    f[i][j]=f[i][k]+f[k][j];
                    g[i][j]=g[i][k]*g[k][j];
                }else if(f[i][j]==f[i][k]+f[k][j]){
                    g[i][j]+=g[i][k]*g[k][j];
                }
            }
        }
    }
    ll ans=0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(g[i][j]==2) ans++;
        }
    }
    return ans;
}
ll sola(){
    ll cha=x[n]-x[n-1];
    d/=cha;
    if(d==0||d==1||d>=n-1) return 0;
    ll ans=n-(2*d-1);
    return ans;
    
}
ll solb(){
    int wei=0;
    for(int i = 1;i<=n;i++)
        if(x[i]-x[1]<=d&&x[n]-x[i]<=d){wei=i;break;}
    if(wei==1||wei==n) return 0;
    if(x[wei+1]-x[wei-1]>d) return 0;
    int p=wei+1;
    while(x[p]-x[wei-1]<=d&&p<=n) p++;
    p=p-wei-1;
    ll ans=0;
    for(int i = 1;i<wei;i++){
        if(x[wei+1]-x[i]>d) ans+=p;
        else if(x[min(n,wei+2)]-x[i]>d) ans+=max(0,n-wei-p);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i<=n;i++) cin >> x[i];
        if(c==11||c==12) cout << sola() << "\n";
        else if(c==13||c==14) cout << solb() << "\n";
        else cout << sol() << "\n";
    }

    return 0;
}