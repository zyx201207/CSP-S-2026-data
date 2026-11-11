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

const int N=2000005;
const int inf=1e18;

int c,T,n,d,ans;
int x[N];
int nex[N],pre[N];
int pos[N],tot[N];
int f[N][2];

i32 main() {
    // FRR("migrate6.in");
    // FRW("my.out");
    FRR("migrate.in");
    FRW("migrate.out");
    scanf("%lld %lld",&c,&T);
    while (T--) {
        scanf("%lld %lld",&n,&d);
        // cout<<"test: "<<n<<" ";
        _rep(i,1,n) scanf("%lld",&x[i]);
        _rep(i,1,n) {
            f[i][0]=f[i][1]=0;
            pos[i]=inf;
            tot[i]=0;
        }
        ans=0;
        int l=1;
        _rep(r,1,n) {
            while (x[r]-x[l]>d) ++l;
            pre[r]=l;
        }
        int r=n;
        _rrep(l,n,1) {
            while (x[r]-x[l]>d) --r;
            nex[l]=r;
        }
        _rep(i,1,n) if (pre[i]!=i) {
            pos[pre[i]]=min(pos[pre[i]],i);
            tot[pre[i]]++;
        }
        // cout<<"nex: "; _rep(i,1,n) cout<<nex[i]<<" "; cout<<endl;
        // cout<<"pre: "; _rep(i,1,n) cout<<pre[i]<<" "; cout<<endl;
        // cout<<"pos: "; _rep(i,1,n) cout<<pos[i]<<" "; cout<<endl;
        // cout<<"tot: "; _rep(i,1,n) cout<<tot[i]<<" "; cout<<endl;
        int del=n;
        _rrep(i,n,1) {
            int j=nex[i],k=nex[nex[i]];
            while (del>k) {
                if (pre[del]!=del) tot[pre[del]]--;
                del--;
            }
            int p=pos[i],cnt=tot[j-1];
            int addcnt=0;
            if (pre[j-1]==i) addcnt+=tot[j-1];
            if (i+1!=j && j!=k && pre[k]==j-1) {
                cnt+=f[k][0]-1;
                if (pre[j-1]==i) addcnt+=f[k][0]-1;
            }
            // cout<<"============================"<<endl;
            // printf("j, k, p, cnt, addcnt = %lld, %lld, %lld, %lld, %lld\n",j,k,p,cnt,addcnt);
            if (j==i) {
                f[i][0]=1;
                f[i][1]=0;
            } else {
                if (pre[j]<i) {
                    f[i][0]=1;
                    f[i][1]=0;
                    if (i+1!=j && j!=k) ans+=cnt;
                } else { // pre[j] == i
                    f[i][0]=f[j][0]+(j-p)+1;
                    f[i][1]=f[j][1];
                    // cout<<"f1: "<<f[j][1]<<endl;
                    if (i+1!=j && j!=k) {
                        // cout<<"f1 add: "<<addcnt<<endl;
                        f[i][1]+=addcnt;
                        ans+=cnt;
                    }
                }
                ans+=f[j][1];
            }
            // printf("f[%lld] = %lld, %lld\n",i,f[i][0],f[i][1]);
            // printf("current ans: %lld\n",ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

/*
17:47 done
*/

/*
0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956

ans = 7
*/

/*
0 1
10 21
0 7 14 21 28 35 42 49 56 63

ans = 5
*/

/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994
-999999999999999993 -999999999999999992 -999999999999999991
-999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

ans = 9
*/

/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558
-111111111111111116 111111111111111105
333333333333333326 555555555555555547 999999999999999989

ans = 6
*/