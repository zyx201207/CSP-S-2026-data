#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000005
#define par array<int, 3>
int c, T, n, nx[N], val[N*4];
ll d, x[N], ans;
inline par Decode(int x){int z=!(x&1);x>>=1;int y=!(x&1);x>>=1;return {x, y, z};}
inline int nxt(int nw){
    par t=Decode(nw);int x=t[0], y=t[1], z=t[2];
    int f=x, g=x-y, h=max(0, g-z);
    int F=nx[f], G=max(nx[g], nx[f]-1), H=max({nx[h], nx[g]-1, nx[f]-2, min(nx[g], nx[f]-1)});
    f=F;g=G;h=H;h=g-h;g=f-g;return ((f<<2)|((!g)<<1)|(!h));
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> T;
    while(T--){
        cin >> n >> d;for(int i=1; i<=n; i++)cin >> x[i];int r=1;ans=0;
        for(int i=1; i<=n; i++){
            while(r<n&&x[r+1]-x[i]<=d)r++;
            nx[i]=r;
        }for(int i=n*4+3; i>=4; i--){
            par t=Decode(i);t[2]=max(0, t[0]-t[1]-t[2]);t[1]=t[0]-t[1];
            val[i]=val[nxt(i)]+max(0, nx[t[1]]-max(t[0], nx[t[2]]));
        }for(int i=1; i<=n; i++)ans+=val[nx[i]<<2];
        cout << ans << '\n';
        for(int i=4; i<=n*4+3; i++)val[i]=0;
    }
    return 0;
}