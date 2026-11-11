#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
inline void read(int &x){
    x=0;bool neg=0;char c=getchar();
    for(;!isdigit(c);c=getchar())neg=(c=='-');
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(neg)x=-x;
}
inline void chmx(int &x,int y){
    x<y?x=y:0ll;
}
inline void chmn(int &x,int y){
    x>y?x=y:0ll;
}
struct solution4{
    int n,d;
    void slv(){
        read(n),read(d);
        vector<int>x(n+1),l(n+1),r(n+1),cl(n+1),cr(n+1),pl(n+1),pr(n+1),sl(n+1),sr(n+1);
        for(int i=1;i<=n;i++)read(x[i]);
        l[0]=r[0]=1;
        for(int i=1;i<=n;i++){
            l[i]=l[i-1],r[i]=r[i-1];
            while(x[i]-x[l[i]]>d)l[i]++;
            while(r[i]<n&&x[r[i]+1]-x[i]<=d)r[i]++;
        }
        for(int i=1;i<=n;i++)pr[r[i]]=i;
        for(int i=n;i>=1;i--)pl[l[i]]=i;
        for(int i=1;i<=n;i++){
            cl[i]=1;
            if(pr[i])cl[i]+=min(pr[i],i-1)-l[i]+1;
            else continue;
            cl[i]+=cl[l[i]]-1;
        }
        for(int i=n;i>=1;i--){
            cr[i]=1;
            if(pl[i])cr[i]+=r[i]-max(pl[i],i+1)+1;
            else continue;
            cr[i]+=cr[r[i]]-1;
        }
        for(int i=1;i<=n;i++){
            // cout<<i<<" "<<l[i]<<" "<<r[i]<<" "<<cl[i]<<" "<<cr[i]<<endl;
            if(l[i]<i-1)sl[l[i]]+=(r[l[i]+1]==i?cr[i]:1ll);
            if(r[i]>i+1)sr[r[i]]+=(l[r[i]-1]==i?cl[i]:1ll);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=sl[i]*sr[i+1];
        }
        printf("%lld\n",ans);
    }
};
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // cout<<1<<endl;
    int c,t;read(c),read(t);
    // cout<<c<<" "<<t<<endl;
    while(t--){
        solution4().slv();

    }
}