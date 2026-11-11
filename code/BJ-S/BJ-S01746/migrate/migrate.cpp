#include<iostream>
using namespace std;

#define int long long 
const int N=2e6+10;
int X[N],Y[N],a[N],L[N],R[N];

void Solve1() {
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++) X[i]=Y[i]=L[i]=R[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=a[1]-1,a[n+1]=a[n]+1;
    for(int i=1,pt=0;i<=n;i++) {
        while(a[i]-a[pt]>d) pt++;
        L[i]=pt;
    }for(int i=n,pt=n+1;i>=1;i--) {
        while(a[pt]-a[i]>d) pt--;
        R[i]=pt;
    }int ret=0;
    for(int i=1;i<n;i++) {
        for(int j=i+1;j<=n;j++) {
            int p=i,pt=1,flg=0;X[1]=i;
            while(p<j) {
                // cout<<p<<endl;
                if(R[p]==p) {flg=1;break;}
                if(R[p]>=j) break;
                X[pt+1]=R[p];
                p=R[p],pt++;
            }X[pt+1]=j;
            if(flg) break;
            p=j,pt=1;Y[1]=j;
            while(p>i) {
                if(L[p]<=i) break;
                Y[pt+1]=L[p];
                p=L[p],pt++;
            }Y[pt+1]=i;pt++;
            // cout<<' '<<i<<' '<<j<<endl;
            int flg2=0,ex=0,lx=0;
            for(int i2=1;i2<=pt;i2++) {
                if(X[i2]==Y[pt-i2+1]) {
                    lx=0;
                }
                else if(X[i2]==Y[pt-i2+1]+1) {
                    if(lx==0) ex++;
                    lx++;
                }
                else {flg2=1;break;}
                if(ex==2 || lx==2) {flg2=1;break;}
            }
            if(flg2==0 && ex==1) {
                ret++;
            //     cout<<i<<' '<<j<<endl;
            // for(int i2=1;i2<=max(1ll,pt);i2++) cout<<X[i2]<<' '; cout<<endl;
            // for(int i2=1;i2<=max(1ll,pt);i2++) cout<<Y[i2]<<' '; cout<<endl;
            
            }
        }
    }
    // cout<<"  "<<' '<<ret<<endl;
    cout<<ret<<endl;
}

void Solve2() {
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++) X[i]=Y[i]=L[i]=R[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    int gc=a[2]-a[1];
    if(gc>=d) cout<<0<<endl;
    else cout<<max(0ll,n-2*d/gc+1)<<endl;
}

void Solve3() {
    int n,d;cin>>n>>d;long long ret=0;
    for(int i=1;i<=n;i++) cin>>a[i];a[0]=a[1]-1;
    for(int i=1,pt=0;i<=n;i++) {
        while(pt<n && a[pt]<a[i]+d) pt++;
        if(pt-i+1==4) ret++;
        // cout<<i<<' '<<pt<<endl;
    }cout<<ret<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--) {
        if(c<=10) Solve1();
        if(11<=c && c<=12) Solve2();
        if(13<=c && c<=14) Solve3();
    }
    return 0;
}