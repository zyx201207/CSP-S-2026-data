#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
long long a[MAXN];
int id[MAXN],sz[MAXN],tot;
struct node
{
    long long x;
    int id;
    short op;
}c[3*MAXN];
bool cmp(node x,node y)
{
    if (x.x!=y.x)return x.x<y.x;
    return abs(x.op)>abs(y.op);
}
int q[MAXN],fr=1,top=1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int cf,t;
    cin >> cf >> t;
    while (t--)
    {
        tot=0;
        fr=1,top=1;
        int n;
        long long d;
        cin >> n >> d;
        for (int i=1;i<=n;i++)cin >> a[i];
        for (int i=1;i<=n;i++)id[i]=i;
        fill(sz+1,sz+n+1,0);
        for (int i=1;i<=n;i++)
        {
            while (top-1>=fr && a[i]-a[q[fr]]>d)fr++;
            int l=1,r=1;
            if (top-fr==1)
            {
                if (a[q[fr]]+d<a[i+1])id[i]=id[q[fr]];
            }
            else if (top-fr>=2)
            {
                l=a[q[fr+1]]-d;
                if (top-fr==2)r=a[i]-d;
                else r=a[q[fr+2]]-d;
            }
            //cout << l << " " <<r << "\n";
            c[++tot].x=l;
            c[tot].id=i;
            c[tot].op=1;
            c[++tot].x=r;
            c[tot].id=i;
            c[tot].op=-1;
            c[++tot].x=a[i];
            c[tot].id=i;
            c[tot].op=0;
            q[top++]=i;
        }
        for (int i=1;i<=n;i++)sz[id[i]]++;
        //for(int i=1;i<=n;i++)cout << sz[i] << " ";
        //cout << "\n";
        sort(c+1,c+3*n+1,cmp);
        long long lastx=LLONG_MIN;
        int sum=0;
        long long ans=0;
        for (int i=1;i<=3*n;i++)
        {
            sum+=c[i].op;
            if (c[i].op==0)ans+=1ll*sz[c[i].id]*sum;
        }
        cout << ans << "\n";
    }
    return 0;
}
