#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pow power
#define ull unsigned ll
template<typename T>void read(T &x){
    x=0; int f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    } 
    while(isdigit(c)) x=10*x+c-'0',c=getchar();
    x*=f;
}
template<typename T>void write(T x){
    if(x<0) putchar('-'),write(-x);
    else if(x<10) putchar(x+'0');
    else write(x/10),putchar(x%10+'0');
}
template<typename T>void writesp(T x){write(x);putchar(' ');}
template<typename T>void writeln(T x){write(x);putchar('\n');}
const int N=5e5+5;
int n;
ll m,a[N],s[N];
bool check(int x){
    for(int i=x;i<=n;i++){
       ll nd=a[i]*x-(s[i]-s[i-x]);
       if(nd<=m) return 1; 
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    writeln(ans);
    return 0;
}