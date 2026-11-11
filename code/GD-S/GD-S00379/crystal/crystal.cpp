#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _iter(it,a) for (auto it=a.begin();it!=a.end();++it)
#define _riter(it,a) for (auto it=a.rbegin();it!=a.rend();++it)
#define _all(a) (a).begin(),(a).end()
#define _rall(a) (a).rbegin(),(a).rend()

#define i32 signed
#define i64 long long
#define u32 unsigned
#define u64 unsigned long long

typedef pair<int,int> pii;

const int N=500005;

int n,m,ans;
int a[N];
int pre[N];

i32 main() {
    // FRR("crystal4.in");
    // FRW("my.out");
    FRR("crystal.in");
    FRW("crystal.out");
    scanf("%lld %lld",&n,&m);
    _rep(i,1,n) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    _rep(i,1,n) pre[i]=pre[i-1]+a[i];
    ans=1;
    _rep(i,1,n) {
        int l=1,r=i;
        while (l<r) {
            int mid=l+r>>1;
            int cnt=a[i]*(i-mid+1)-(pre[i]-pre[mid-1]);
            if (cnt<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-r+1);
    }
    printf("%lld",ans);
    return 0;
}

/*
14:35 ~ 14:40
*/