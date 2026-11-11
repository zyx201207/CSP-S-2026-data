#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
#define lop(a,b,c) for (int a = b ; a <= c ; ++a)
using namespace std;
int a[500005],b[500005],n,m,lst[500005],rd[300005],ans[300005];
void add(int x,int y)
{
    for (;x<=n+1;x+=lowbit(x))
    {
        b[x]+=y;
    }
}
int query(int x)
{
    int tot=0;
    for (;x;x-=lowbit(x))
    {
        tot+=b[x];
    }
    return tot;
}
void add(int x,int y,int z)
{
    add(x,z);
    add(y+1,-z);
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
    bool f=1;
    cin >> n >> m;
    loop(i,n) 
    {
        cin >> a[i];
        if (a[i]<a[i-1]) f=0;
        lst[i]=rd[a[i]];
        rd[a[i]]=i;
    }
    if (f)
    {
        loop(i,n)
        {
            if (a[i-1]!=a[i])
            {
                ans[a[i-1]]+=i-1;
            }
        }
        ans[a[n]]+=n;
        loop(i,m) cout << ans[i] << " ";
        return 0;
    }
    loop(i,n)
    {
        loop(j,n) b[j]=0;
        lop(j,i,n)
        {
            int t=lst[j];
            while (t>=i&&query(t)!=0) t=lst[t];
            if (t>=i)
            {
                add(t,j-1,1);
            }
        }

        lop(j,i,n)
        {
            if (query(j)==0) ans[a[j]]++;
        }
    }
    loop(i,m) cout << ans[i] << " ";
	return 0;
}


