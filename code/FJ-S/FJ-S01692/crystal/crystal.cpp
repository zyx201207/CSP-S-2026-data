#include<bits/stdc++.h>
#define int __int128
#define R read()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define gc getchar
using namespace std;
int read()
{
    int x=0,f=1;
    char c=gc();
    while(c<'0'||c>'9') (c=='-'&&(f=-1,1)),c=gc();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=gc();
    return x*f;
}
void write(int x,char xx)
{
    static int st[35],tot=0;
    if(x<0) putchar('-'),x=-x;
    do{st[++tot]=x%10,x/=10;}
    while(x);
    while(tot) putchar(st[tot]+'0'),tot--;
    putchar(xx);
}
#define N 500010
int n,m,a[N],ans,sum;
queue<int>Q;
void solve()
{
    n=R,m=R;
    for(int i=1;i<=n;i++) a[i]=R;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        while(!Q.empty()&&sum+m<Q.size()*a[i]) sum-=Q.front(),Q.pop();
        ans=max(ans,(int)Q.size()+1),Q.push(a[i]),sum+=a[i];
    }
    write(ans,'\n');
}
int T=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // T=R;
    while(T--) solve();
    return 0;
}
/*
14:42 100pts
*/