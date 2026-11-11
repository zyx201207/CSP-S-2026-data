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
const int N=2e6+5;
ll a[N];ll d;
int n;
int tor[N],tol[N];
int grtr[N],grtl[N];
ll ans;
void solve()
{
    ans=0;
    read(n);read(d);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) tor[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
    for(int i=1;i<=n;i++) tol[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
    // for(int i=1;i<=n;i++) cout<<tol[i]<<" "<<tor[i]<<endl;cout<<"__"<<endl;
    for(int i=n;i>=1;i--)
    {
        grtr[i]=0;
        if(tol[tor[i]]==i) grtr[i]=grtr[tor[i]]+tor[i]-(lower_bound(tol+1,tol+n+1,i)-tol)+1;
        else if(tol[tor[i]]>i) grtr[i]=(upper_bound(tol+1,tol+n+1,i)-tol-1)-max(i+1,(int)(lower_bound(tol+1,tol+n+1,i)-tol))+1;
        grtr[i]=max(grtr[i],0);
    }
    for(int i=1;i<=n;i++)
    {
        grtl[i]=0;
        if(tor[tol[i]]==i) grtl[i]=grtl[tol[i]]+(upper_bound(tor+1,tor+n+1,i)-tor-1)-tol[i]+1;
        else if(tor[tol[i]]<i) grtl[i]=min(i-1,(int)(upper_bound(tor+1,tor+n+1,i)-tor-1))-(lower_bound(tor+1,tor+n+1,i)-tor)+1;
        grtl[i]=max(grtl[i],0);
    }
    for(int i=2;i<=n;i++)
    {
        int lval,rval;
        if(tol[i-1]==i-1||tor[i]==i) continue;
        if(tol[tor[i]]==i-1) rval=grtr[tor[i]]+tor[i]-(lower_bound(tol+1,tol+n+1,i-1)-tol)+1;
        else if(tol[tor[i]]>i-1) 
        {
            rval=(upper_bound(tol+1,tol+n+1,i-1)-tol-1)-max(i+1,(int)(lower_bound(tol+1,tol+n+1,i-1)-tol))+1;
            // cout<<"qwq"<<(upper_bound(tol+1,tol+n+1,i-1)-tol-1)<<" "<<max(i,(int)(lower_bound(tol+1,tol+n+1,i-1)-tol))<<endl;
        }
        else rval=0;
        if(tor[tol[i-1]]==i) lval=grtl[tol[i-1]]+(upper_bound(tor+1,tor+n+1,i)-tor-1)-tol[i-1]+1;
        else if(tor[tol[i-1]]<i) 
        {
            lval=min(i-2,(int)(upper_bound(tor+1,tor+n+1,i)-tor-1))-(lower_bound(tor+1,tor+n+1,i)-tor)+1;
            // cout<<"qwq"<<min(i-2,(int)(upper_bound(tor+1,tor+n+1,i)-tor-1))<<" "<<(lower_bound(tor+1,tor+n+1,i)-tor)<<endl;
        }
        else lval=0;
        lval=max(lval,0);
        rval=max(rval,0);
        // cout<<i<<" "<<lval<<" "<<rval<<endl;
        ans+=1ll*lval*rval;
    }
    writeln(ans);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int cid,T;
    read(cid);read(T);
    while(T--) solve();
    return 0;
}
//g++ tmp.cpp -o tmp -std=c++14 -O2 -Wall -Wextra -static