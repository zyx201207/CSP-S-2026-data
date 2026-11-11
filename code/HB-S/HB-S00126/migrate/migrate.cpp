#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char getc()
{
    static constexpr int SIZ = 1 << 16;
    static char buf[SIZ],*p1 = buf,*p2 = buf;
    if(p1 == p2) p2 = (p1 = buf) + fread(buf,1,SIZ,stdin);
    return p1 == p2?EOF:*p1++;
}

template <typename T>
void read(T &x)
{
    bool f = false;
    char c;
    for(c = getc();!isdigit(c) && c != '-';c = getc());
    if(c == '-') c = getc(),f = true;
    for(x = 0;isdigit(c);c = getc())
        x = x * 10 + (c ^ '0');
    if(f) x = -x;
}

constexpr int N = 2000015;
int n,c,ql[N],hl[N],qlk[N],qc[N],hc[N],hlk[N],l1,r1,l2,r2;
ll nl[N],d,ans;

// int get(ll l,ll r)
// {
//     // printf("get [%lld,%lld]\n",l,r);
//     int ans = upper_bound(nl + 1,nl + n + 1,r) - lower_bound(nl + 1,nl + n + 1,l);
//     // printf("ans %d\n",ans);
//     return max(0,int(upper_bound(nl + 1,nl + n + 1,r) - lower_bound(nl + 1,nl + n + 1,l)));
// }

int get1(int x) {return max(0,min(r1,x - 1) - l1 + 1);}
int get2(int x) {return max(0,r2 - max(l2,x + 2) + 1);}

void calc(int x)
{
    if(nl[x + 1] - nl[x] >= d) return;
    // printf("calc %d\n",x);
    if(ql[x] == ql[x + 1] && hl[x] == hl[x + 1] && ql[x - 1] != ql[x] && hl[x + 2] != hl[x])
        ans += ll(qc[ql[x]] - 1) * (hc[hl[x]] - 1);
    // printf("ans %lld\n",ans);
    if(ql[x] == ql[x + 1] && ql[x - 1] != ql[x])
    {
        // printf("ql[x] %d, qc[ql[x]] %d\n",ql[x],qc[ql[x]]);
        ans += ll(qc[ql[x]] - 1) * max(0,min(r1,x - 1) - l1 + 1);
    }
    // printf("ans %lld\n",ans);
    if(hl[x] == hl[x + 1] && hl[x + 2] != hl[x])
        ans += ll(hc[hl[x]] - 1) * max(0,r2 - max(l2,x + 2) + 1);
    // printf("ans %lld\n",ans);
    ans += (ll)max(0,min(r1,x - 1) - l1 + 1) * max(0,r2 - max(l2,x + 2) + 1);
    // printf("ans %lld\n",ans);
}

void solve()
{
    read(n);read(d);
    for(int i = 1;i <= n;i++)
        read(nl[i]);
    if(n == 2)
    {
        printf("0\n");
        return;
    }
    int p = 1;
    for(int i = 1;i <= n;i++)
    {
        while(p < n && nl[p + 1] - nl[i] <= d) p++;
        ql[i] = p;
        // printf("ql[%d] = %d\n",i,ql[i]);
    }
    p = n;
    for(int i = n;i;i--)
    {
        while(p > 1 && nl[i] - nl[p - 1] <= d) p--;
        hl[i] = p;
    }
    for(int i = 1;i <= n;i++)
        qlk[i] = (hl[ql[i]] == i?ql[i]:-1);
    for(int i = 1;i <= n;i++)
        hlk[i] = (ql[hl[i]] == i?hl[i]:-1);
    memset(qc,0,(n + 1) * sizeof(int));
    memset(hc,0,(n + 1) * sizeof(int));
    for(int i = 1;i <= n;i++)
    {
        if(ql[i] != i && qlk[i] != ql[i])hc[ql[i]]++;
        if(hl[i] != i && hlk[i] != hl[i])qc[hl[i]]++;
    }
    // printf("qq: ");
    // for(int i = 1;i <= n;i++)
    //     printf("%d ",qq[i]);
    // printf("\n");
    // printf("ql: ");
    // for(int i = 1;i <= n;i++)
    //     printf("%d ",ql[i]);
    // printf("\n");
    // printf("hl: ");
    // for(int i = 1;i <= n;i++)
    //     printf("%d ",hl[i]);
    // printf("\n");
    // printf("qlk: ");
    // for(int i = 1;i <= n;i++)
    //     printf("%d ",qlk[i]);
    // printf("\n");
    // printf("qc: ");
    for(int i = n;i;i--)
    {
        if(qlk[i] != -1 && qlk[i] != i)
            qc[i] += qc[qlk[i]] + 1;
        else qc[i] += 1;
        // printf("%d ",qc[i]);
    }
    // printf("\n");
    // printf("hc: ");
    for(int i = 1;i <= n;i++)
    {
        if(hlk[i] != -1 && hlk[i] != i)
            hc[i] += hc[hlk[i]] + 1;
        else hc[i] += 1;
        // printf("%d ",hc[i]);
    }
    // printf("\n");
    ans = 0;
    l1 = l2 = 1,r1 = r2 = 0;
    for(int i = 2;i + 1 < n;i++)
    {
        while(l1 <= n && nl[l1] < nl[i + 1] - d) l1++;
        while(l2 <= n && nl[l2] < nl[i - 1] + 1 + d) l2++;
        while(r1 + 1 <= n && nl[r1 + 1] <= nl[i + 2] - 1 - d) r1++;
        while(r2 + 1 <= n && nl[r2 + 1] <= nl[i] + d) r2++;
        calc(i);
    }
    printf("%lld\n",ans);
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;
    read(c);read(T);
    while(T--)
        solve();
    // cerr << clock() / 1e6 << "s" << endl;
    return 0;
}