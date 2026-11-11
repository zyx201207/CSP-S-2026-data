#include <bits/stdc++.h>
#define For(e,e1,e2) for(int e=(e1);e<=(e2);e++)
#define For_(e,e1,e2) for(int e=(e1);e<(e2);e++)
#define Rof(e,e1,e2) for(int e=(e2);e>=(e1);e--)
#define Rof_(e,e1,e2) for(int e=(e2);e>(e1);e--)
#define LL long long
#define ULL unsigned long long
#define DB double
#define cint const int
#define cLL const long long
#define ft first
#define sc second
#define vct vector
#define pb push_back
#define all(ev) ev.begin(),ev.end()
#define sz(ev) ((int)ev.size())
#define exc(ev) if(ev) continue
#define stop(ev) if(ev) break
#define ret(ev) if(ev) return 
#define x0 __xx00__
#define x1 __xx11__
#define y0 __yy00__
#define y1 __yy11__
using namespace std;

void get_max(int &w1,cint w2)
{
    if(w2>w1) w1=w2;
}
void main_init()
{

}
cint N=1000020;
int n,m,d;
vct <int> v[N];
#define Info array <int,3>
const Info emp=(Info){-1,0,0};
// use,dis,dep
Info operator + (Info w1,Info w2)
{
    if(!~w1[0]) return w2;
    if(!~w2[0]) return w1;
    if(!w2[1]) swap(w1,w2);
    if(!w1[1])
    {
        w1[0]+=(w2[0]-(!w2[1]));
        return w1;
    }
    if(!w2[0]) swap(w1,w2);
    if(!w1[0])
    {
        if(w1[2]+w2[1]>d)
        {
            int t=w1[2]+w2[1]-d;
            w2[0]+=t,w2[1]=max(w2[1]-t,0);
            if(!w2[1]) w2[2]=0;
        }
        else
            get_max(w2[2],w1[2]);
        return w2;
    }
    w1[0]+=(w2[0]+w1[1]+w2[1]-1);
    w1[1]=w1[2]=0;
    return w1;
}
Info & operator += (Info &w1,Info w2)
{
    return (w1=(w1+w2));
}
Info operator << (Info w1,cint w2)
{
    if(!~w1[0]) w1[0]=0;
    if(w1[1]||!w1[0]) w1[2]++;
    w1[1]++;
    if(w1[2]>d)
    {
        w1[0]++;
        w1[1]=w1[2]=1;
    }
    return w1;
}
Info dfs(int p,int fa)
{
    Info t=emp;
    for(auto i:v[p]) if(i!=fa)
        t+=(dfs(i,p)<<1);
    // printf("%d,%d:%d,%d,%d\n",p,fa,t[0],t[1],t[2]);
    // auto t2=(t<<1);
    // printf(">   %d,%d,%d\n",t2[0],t2[1],t2[2]);
    return t;
}
bool check(int d_)
{
    d=d_;
    if(m==1) return (dfs(1,0)[0]<=m);
    // printf("d=%d\n",d);
    For(i,1,n) for(auto j:v[i]) if(i<j)
    {
        int w1=max(dfs(i,j)[0],1),w2=max(dfs(j,i)[0],1);
        // printf("%d,%d : %d,%d\n",i,j,w1,w2);
        if(w1+w2<=m)
            return true;
    }
    return false;
}
void main_solve()
{
    scanf("%d%d",&n,&m);
    For(i,1,n) v[i].clear();
    For_(i,1,n)
    {
        int x,y; scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    if(n==m)
    {
        printf("0\n");
        return ;
    }
    // check(1); return ;
    int L=0,R=n-1,MD;
    while(L+1<R) (check(MD=L+R>>1)?R:L)=MD;
    printf("%d\n",R);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    main_init();
    int __,_; scanf("%d%d",&__,&_); while(_--)
        main_solve();
    return 0;
}