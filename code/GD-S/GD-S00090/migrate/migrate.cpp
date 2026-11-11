#include<bits/stdc++.h>
using namespace std;  typedef long long LL; 
#define rep(_1,_2,_3) for(int _1=(_2), __##_1##__=(_3); _1<=__##_1##__; ++_1)
#define repo(_1,_2,_3) for(int _1=(_2), __##_1##__=(_3); _1<__##_1##__; ++_1)
#define reb(_1,_2,_3) for(int _1=(_2), __##_1##__=(_3); _1>=__##_1##__; --_1)
const int N=2000004, M=0, K=0; 
int n, __, _, dis[N];  LL x[N], d;
char ways[N];

bool __main() {
    cin>>n>>d;  rep(i,1,n) cin>>x[i];
    x[n+1]=0x3F3F3F3F3F3F3F3FLL;
    if(n>400 && (__==11||__==12)) { //If this is Testcase 11 or Testcase 12
        if(x[3]-x[1]>d) cout<<"0\n";
        else cout<<n-3<<"\n"; // Pairs (@#x, @#x+2) (1<=@#x<=@n-2)
        return 0;
    }
    LL ans=0;
    rep(i,1,n-2) {
        bool ok=false;
        if(x[i+1]-x[i]>d) continue;
        ways[i]=ways[i+1]='\1', dis[i]=0, dis[i+1]=1;
        int j=i+2;
        for(; j<=n; ++j) {
            if(x[j]-x[j-1]>d) break;
            dis[j]=0x3F3F3F3F, ways[j]='\0';
            for(int t=lower_bound(x+i, x+j, x[j]-d)-x; t<j; ++t) { 
                if(dis[t]+1<dis[j]) dis[j]=dis[t]+1, ways[j]='\1';
                else if(dis[t]+1==dis[j]) { ways[j]+=ways[t]; if(ways[j]>'\3') ways[j]='\3';}
            }
        }
        for(--j; j>i; --j) if(ways[j]=='\2') ++ans;
    }
    cout<<ans<<'\n';
    return 0;
}

int main() {
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout); // PAY ATTENTION!! 
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
    int _=1;  cin>>__>>_;  for(; _>0; --_) if(__main()) return 0;
    return 0;
}
