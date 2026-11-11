#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N=2e6+10;

int n;
long long x[N],d,pos[N],tot;
int st[5010][5010];

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) {
        cin>>n>>d;
        for (int i=1;i<=n;i++) cin>>x[i];
        if (c>=11 && c<=12) {
            long long k=d/abs(x[2]-x[1]);
            if (k<2) cout << 0 << '\n';
            else cout << max(n-(k*2-1),0ll) << '\n';
        }else{
            int last=0,ans=0;
            for (int i=1;i<=n;i++) {
                for (int j=i;j<=n;j++) {
                    last=i,tot=0;
                    pos[++tot]=last;
                    bool st=0;
                    for (int k=i;k<=j;k++) {
                        if (x[k]-x[last]>d) {
                            last=k-1;
                            if (x[k]-x[last]>d) {
                                st=1;
                                break;
                            }
                            pos[++tot]=last;
                        }
                    }
                    pos[++tot]=j;
                 //   for (int i=1;i<=tot;i++) cout << pos[i] << ' ';
                    if (st) continue;
                    int cnt=1;
                    for (int k=2;k<tot;k++)
                    for (int p=pos[k-1]+1;p<=pos[k+1]-1;p++) {
                        if (x[p]-x[pos[k-1]]<=d && x[pos[k+1]]-x[p]<=d && p!=pos[k]) cnt++;
                        if (cnt>2) break;
                    }
                 //   cout << cnt << ' ';
                    if (cnt==2) ans++;
               }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
