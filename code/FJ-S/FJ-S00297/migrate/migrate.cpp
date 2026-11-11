#include<iostream>

#define int long long
#define i128 __int128

using namespace std;

const int N = 2e6 + 5,
inf = 1e18;

struct node
{
    int w,c;
};

struct SGT
{
    int t1[N << 2],t2[N << 2];
    void build(int k,int l,int r)
    {
        if(l == r)
        {
            t1[k] = inf;
            t2[k] = 0;
            return ;
        }
        int mid = (l + r) >> 1;
        build(k << 1,l,mid);
        build(k << 1 | 1,mid + 1,r);
    }

    void pushup(int k)
    {
        // if(t1[k << 1] == t1[k << 1 | 1]) t2[k] = t2[k << 1 | 1] + t2[k << 1];
        // else if(t1[k << 1] < t1[k << 1 | 1]) t2[k] = t2[k << 1]
        t1[k] = min(t1[k << 1],t1[k << 1 | 1]);
        t2[k] = t1[k << 1] == t1[k] ? t2[k << 1] : 0ll + t1[k << 1 | 1] == t1[k] ? t2[k << 1 | 1] : 0ll;
    }

    void upd(int k,int l,int r,int pos,int w,int c)
    {
        if(l == r)
        {
            t1[k] = w;
            t2[k] = c;
            return ;
        }

        int mid = (l + r) >> 1;
        if(pos <= mid) upd(k << 1,l,mid,pos,w,c);
        else upd(k << 1 | 1,mid + 1,r,pos,w,c);
        pushup(k);
    }

    node query(int k,int l,int r,int l1,int r1)
    {
        if(l > r) return {inf,0ll};
        if(l > r1 || l1 > r) return {inf,0ll};
        if(l1 <= l && r <= r1) return {t1[k],t2[k]};
        int mid = (l + r) >> 1;
        node L = query(k << 1,l,mid,l1,r1),R = query(k << 1 | 1,mid + 1,r,l1,r1);
        if(L.w < R.w) return L;
        if(R.w < L.w) return R;
        return {L.w,L.c + R.c};
    }
}T;

int n,d,a[N];
void solve()
{
    cin >> n >> d;
    int ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        T.build(1,1,n);
        T.upd(1,1,n,i,0,1);
        for(int j = i + 1; j <= n; j++)
        {
            int l = i,r = j - 1,res = j;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                if((i128)a[j] <= i128(d + a[mid])) res = mid,r = mid - 1;
                else l = mid + 1;
            }
            // if(res > j - 1) break;
            node f = T.query(1,1,n,res,j - 1);
            // if(i == 1) cout << f.w << " " << f.c << "\n";
            if(f.c == 2)
            {
                ans++;
                // cout << f.w << " " << f.c << "\n";
                // cout << i << " " << j << "\n";
            }
            T.upd(1,1,n,j,f.w + 1,f.c);
        }
    }
    cout << ans << "\n";
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c,T; cin >> c >> T;
    while(T--) solve();
}