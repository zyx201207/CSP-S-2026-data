#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,l[N],r[N],las[N],nxt[N];
long long ans,d,x[N],cnt[2][N];
inline void file(){freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> c >> t;
    while(t--){
        cin >> n >> d,ans=0;
        for(int i(1);i<=n;++i) cin >> x[i],cnt[0][i]=cnt[1][i]=l[i]=r[i]=nxt[i]=las[i]=0;
        l[1]=1;
        for(int i(2),a(1);i<=n;++i){
            while(x[i]-x[a]>d) r[a]=i-1,++a;
            l[i]=a;
        }
        for(int i(n);!r[i];--i) r[i]=n;
        for(int i(1);i<=n;++i){
            ++cnt[0][i];
            if(l[r[i]]==i) cnt[0][r[i]]+=cnt[0][i];
            else ++cnt[0][r[i]];
        }
        for(int i(n);i;--i){
            ++cnt[1][i];
            if(r[l[i]]==i) cnt[1][l[i]]+=cnt[1][i];
            else ++cnt[1][l[i]];
        }
        for(int i(2),a,b,k,L,R;i<n-1;++i){
            a=l[i],b=r[i+1];
            if(x[i+2]-x[a]<=d||x[b]-x[i-1]<=d||a==i||b==i+1) continue;
            if(l[i+1]==a) L=max(r[i-1]+1,i+2),R=r[i],ans+=(cnt[0][a]-1)*(R-L+1);
            if(r[i]==b) L=l[i+1],R=min(i-1,l[i+2]-1),ans+=(R-L+1)*(cnt[1][b]-1);
            if(l[i+1]==a&&r[i]==b) ans+=(cnt[0][a]-1)*(cnt[1][b]-1);
            k=l[i+1],L=max(r[i-1]+1,i+2),R=r[i];
            if(L<=R) while(k<=l[i+2]-1&&k<i) ans+=R-L+1,++k;
        }
        cout << ans << '\n';
    }
    return 0;
}