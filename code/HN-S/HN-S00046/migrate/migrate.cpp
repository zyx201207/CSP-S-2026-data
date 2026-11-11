#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second

const int N=2'000'010;
int C, T, n, d, ans, x[N], f[N], c[N], b[N];
multiset<pii> s;

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(0);
  for(cin>> C>> T; T--; ) {
    cin>> n>> d, ans=0;
    for(int i=1; i<=n; i++) cin>> x[i];
    if(n==1) { cout<< 0<< '\n'; continue; }
    if(C==11||C==12) {
      int e=x[2]-x[1], t=d/e;
      if(t<=1) cout<< 0<< '\n';
      else cout<< max(0ll, n-2*t+1)<< '\n';
      continue;
    }
    for(int i=1; i<=n; i++) {
      fill(b+1, b+n+1, 0);
      f[i]=0, c[i]=1, b[0]=1;
      for(int j=i+1, k=i, t=0; j<=n; j++) {
        for(; k<=j&&x[j]-x[k]>d; k++) if(!(b[f[k]]-=c[k])) t++;
        f[j]=t+1, c[j]=b[t], b[f[j]]+=c[j];
        if(c[j]==2) ans++;
      }
    }
    cout<< ans<< '\n';
  }
  return 0;
}