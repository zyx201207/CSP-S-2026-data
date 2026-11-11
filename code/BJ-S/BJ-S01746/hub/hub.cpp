#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define int long long 
const int N=2e6+10;
int a[N],L[N],R[N],sL[N],sR[N];
struct node{int pre,nxt;}t11[N],t22[N],t12[N],t21[N];

// struct segT {
//     int sum[N*4];
//     inline void upd(int o,int l,int r,int x,int v) {
//         if(l==r) {sum[o]+=v;return ;}
//         int mid=(l+r)>>1;
//         if(x<=mid) upd(2*o,l,mid,x,v);
//         else upd(2*o+1,mid+1,r,x,v);
//         t[o].sum=t[2*o].sum+t[2*o+1].sum;
//         return ;
//     }
//     inline int qry(int o,int l,int r,int qL,int qR) {
//         if(qL<=l && r<=qR) return t[o].sum;
//         int mid=(l+r)>>1,s=0;
//         if(qL<=mid) s+=qry(2*o,l,mid,qL,qR);
//         if(mid<qR) s+=qry(2*o+1,mid+1,r,qL,qR);
//         return s;
//     }
// }t;

int r2[N],s2[N];

void Solve() {
    int n,d;cin>>n>>d;
    memset(a,0,sizeof a);
    memset(L,0,sizeof L);
    memset(sL,0,sizeof sL);
    memset(R,0,sizeof R);
    memset(sR,0,sizeof sR);
    memset(t11,0,sizeof t11);
    memset(t12,0,sizeof t12);
    memset(t21,0,sizeof t21);
    memset(t22,0,sizeof t22);
    memset(r2,0,sizeof r2);
    memset(s2,0,sizeof s2);
    // memset(t.sum,0,sizeof t.sum);
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=a[1]-d-1,a[n+1]=a[n]+d+1;
    // Calculate L,R
    for(int i=1,pt=0;i<=n;i++) {
        while(a[i]-a[pt]>d) pt++;
        L[i]=pt;
    }for(int i=n,pt=n+1;i>=1;i--) {
        while(a[pt]-a[i]>d) pt--;
        R[i]=pt;
    }
    cerr<<"L: "; for(int i=1;i<=n;i++) cerr<<L[i]<<' '; cerr<<endl;
    cerr<<"R: "; for(int i=1;i<=n;i++) cerr<<R[i]<<' '; cerr<<endl;
    // End.
    // Calculate 11,12,22
    for(int i=1,j;i<=n;i++) {
        j=R[i]; if(j!=i && L[j]==i) t11[i].nxt=j;
        j=L[i]; if(j!=i && R[j]==i) t11[i].pre=j;
        if(i<n) {
            j=R[i];
            if(j!=i+1 && L[j-1]==i) t12[i].nxt=j-1,t21[j-1].pre=i;
            j=R[i+1];
            if(j!=i && L[j-1]==i) t22[i].nxt=j-1;
        } if(i>1) {
            j=L[i];
            if(j!=i-1 && R[j+1]==i) t12[i].pre=j,t21[j].nxt=i;
            j=L[i];
            if(j!=i && R[j+1]==i) t22[i].pre=j;
        }
    }
    cerr<<"t11p: "; for(int i=1;i<=n;i++) cerr<<t11[i].pre<<' '; cerr<<endl;
    cerr<<"t11n: "; for(int i=1;i<=n;i++) cerr<<t11[i].nxt<<' '; cerr<<endl;
    cerr<<"t12p: "; for(int i=1;i<=n;i++) cerr<<t12[i].pre<<' '; cerr<<endl;
    cerr<<"t12n: "; for(int i=1;i<=n;i++) cerr<<t12[i].nxt<<' '; cerr<<endl;
    cerr<<"t21p: "; for(int i=1;i<=n;i++) cerr<<t21[i].pre<<' '; cerr<<endl;
    cerr<<"t21n: "; for(int i=1;i<=n;i++) cerr<<t21[i].nxt<<' '; cerr<<endl;
    cerr<<"t22p: "; for(int i=1;i<=n;i++) cerr<<t22[i].pre<<' '; cerr<<endl;
    cerr<<"t22n: "; for(int i=1;i<=n;i++) cerr<<t22[i].nxt<<' '; cerr<<endl;
    // End.
    for(int i=1;i<=n;i++) sL[i]=sL[t11[i].pre]+1;
    for(int i=n;i>=1;i--) sR[i]=sR[t11[i].nxt]+1;
    cerr<<"sL: "; for(int i=1;i<=n;i++) cerr<<sL[i]<<' '; cerr<<endl;
    cerr<<"sR: "; for(int i=1;i<=n;i++) cerr<<sR[i]<<' '; cerr<<endl;
    // End.
    
    long long ret=0;
    for(int i=n-1;i>=1;i--) {
        if(t22[i].nxt) {
            r2[i]=r2[t22[i].nxt];
            s2[i]=sR[t21[i].nxt]+s2[t22[i].nxt];
        }
        else {r2[i]=i;s2[i]=sR[t21[i].nxt];}
    }
    cerr<<"r2: "; for(int i=1;i<=n;i++) cerr<<r2[i]<<' '; cerr<<endl;
    cerr<<"s2: "; for(int i=1;i<=n;i++) cerr<<s2[i]<<' '; cerr<<endl;
    for(int i=1;i<n;i++) {
        int ls1=sL[t21[i].pre],rs1=s2[i];
        ret+=ls1*rs1;
    }
    // for(int i=1;i<=n;i++) {
    //     ret+=max(0ll,sL[i]-1);
    // }
    cout<<ret<<endl;
    return ;
}

signed main() {
    int c,T;cin>>c>>T;
    while(T--) Solve();
    return 0;
}