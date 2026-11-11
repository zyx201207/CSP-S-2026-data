#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x,y) for(i=x;i<=y;i++)
#define rF(i,x,y) for(i=x;i>=y;i--)
const int N=1e5+5,MOD=1e9+7;
typedef pair<int,int> PII;
string c[5];
void solve()
{
    int i;
    F(i,1,4) cin>>c[i];
    if(c[1]!=c[3]) cout<<"0000";
    else if(!(c[2][0]==c[4][0]&&c[2][1]==c[4][1])) cout<<"1000";
    else if((c[2][2]<='C'&&c[4][2]>'C')||((c[2][2]>'C'&&c[4][2]<='C'))) cout<<"1100";
    else if(abs(c[2][2]-c[4][2])>1) cout<<"1110";
    else cout<<"1111";
    return;
}
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--) {solve();}
}
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x,y) for(i=x;i<=y;i++)
#define rF(i,x,y) for(i=x;i>=y;i--)
const int N=1e5+5,MOD=1e9+7;
typedef pair<int,int> PII;
int n,a[N],r[N];
struct Node
{
    #define mid (l+r>>1)
    int idx;
    struct node
    {
        int ls,rs,cnt;
    }tr[40*N];
    void pushup(int rt)
    {
        tr[rt].cnt=tr[tr[rt].ls].cnt+tr[tr[rt].rs].cnt;
        return;
    }
    void upd(int rt1,int rt2,int l,int r,int x)
    {
        if(l==r)
        {
            tr[rt2].cnt=tr[rt1].cnt+1;
            return;
        }
        if(mid>=x)
        {
            tr[rt2].rs=tr[rt1].rs,tr[rt2].ls=++idx;
            upd(tr[rt1].ls,idx,l,mid,x);
        }
        else
        {
            tr[rt2].ls=tr[rt1].ls,tr[rt2].rs=++idx;
            upd(tr[rt1].rs,idx,mid+1,r,x);    
        }
        pushup(rt2);
        return;
    }
    int query(int rtl,int rtr,int l,int r,int k)
    {
        if(l==r) return l;
        int nw=tr[tr[rtr].ls].cnt-tr[tr[rtl].ls].cnt;
        // cout<<l<<' '<<r<<' '<<tr[rtr].ls<<'\n';
        if(nw>=k) return query(tr[rtl].ls,tr[rtr].ls,l,mid,k);
        else return query(tr[rtl].ls,tr[rtr].ls,mid+1,r,k-nw);
    }
}T;
void solve()
{
    int i;
    cin>>n;
    T.idx=0;
    F(i,1,n) 
    {
        cin>>a[i];
        r[i]=++T.idx;
        T.upd(r[i-1],r[i],1,N-1,a[i]);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,R,k;
        cin>>l>>R>>k;
        cout<<T.query(r[l-1],r[R],1,N-1,k)<<'\n';
    }
    return;
}
signed main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--) {solve();}
}
*/