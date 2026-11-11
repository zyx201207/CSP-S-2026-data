#include<bits/stdc++.h>
#define pow power
#define ll long long
#define ull unsigned long long
using namespace std;
template<typename T>void read(T &x)
{
    x=0;int f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=f;
}
template<typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template<typename T>void writeln(T x){write(x);putchar('\n');}
template<typename T>void writesp(T x){write(x);putchar(' ');}
const int N=5e5+5;
ll a[N];
ll sum[N];
int n;ll m;
bool check(int len)
{
    for(int l=1,r=len;r<=n;l++,r++)
    {
        ll val=a[r]*len-(sum[r]-sum[l-1]);
        if(val<=m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1,r=n;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    writeln(l);
    return 0;
}
//g++ tmp.cpp -o tmp -std=c++14 -O2 -Wall -Wextra -static