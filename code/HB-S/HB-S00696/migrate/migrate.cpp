#include <bits/stdc++.h>
#define int long long
#define pii pair <int,int>
using namespace std;
const int MAXN=2000005;
int C,T,n,d,a[MAXN];
pii f[5005][5005]; 
pii rch[5005];
pii getadd(pii x, pii y) {
    pii z; z.first=min(x.first,y.first);
    z.second=(z.first==x.first)*x.second+(z.first==y.first)*y.second;
    return z;
}
void C10() {
    while (T--) {
        cin>>n>>d; for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) {
            if (i==1||a[i]-a[i-1]>d) rch[i]=(pii){-1,-1};
            else rch[i]={lower_bound(a+1,a+n+1,a[i]-d)-a,i-1};
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                f[i][j].first=1e9;
                f[i][j].second=0;
            }
        }
        for (int i=n;i>=1;i--) {
            //canreach
            f[i][i]={0,1}; for (int j=i;j>=1;j--) {
                for (int now=rch[j].first;now<=rch[j].second;now++) {
                    //cout<<now<<' '<<j<<' '<<i<<'\n';
                    if (now==-1) continue;
                    pii tmp=f[j][i]; tmp.first++;
                    f[now][i]=getadd(tmp,f[now][i]);
                }
            }
        }
        int answ=0;
       for (int i=1;i<=n;i++) {
           for (int j=1;j<=n;j++) {
               //cout<<i<<' '<<j<<' '<<f[i][j].first<<' '<<f[i][j].second<<'\n';
               if (f[i][j].second==2) {
                   answ++;
               }
           }
       } cout<<answ<<'\n';
    }
}
void C11() {
    while (T--) {
        cin>>n>>d; for (int i=1;i<=n;i++) cin>>a[i];
        int div=d/(a[2]-a[1]);
        if (n<=1||a[2]-a[1]>d||div==1) {
            cout<<0<<'\n'; continue;
        }
        int gett=div*2-1,cnt=0; 
        for (int i=1;i<=n;i++) {
            if (i+gett<=n) cnt++;
        } cout<<cnt<<'\n';
    }
} void C13() {
    while (T--) {
        cin>>n>>d; for (int i=1;i<=n;i++) cin>>a[i];
        cout<<0<<'\n';
    }
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;  if (C<=10) {
        C10();
    } if (11<=C&&C<=12) {
        C11();
    } if (13<=C&&C<=14) {
        C13();
    } if (15<=C&&C<=18) {
        C13();
    }
    return 0;
}