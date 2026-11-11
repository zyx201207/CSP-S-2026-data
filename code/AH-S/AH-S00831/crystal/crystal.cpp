#include<bits/stdc++.h>
#define space putchar(' ');
#define endl putchar('\n');
#define debug puts("------------")
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
inline int read();
inline void write(int x);
const int N=5E5+5;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    deque<int> dq;
    int sum=0,presum=0,maxn=-INF;
    for(int i=1;i<=n;i++){
        int sz=dq.size();
        sum+=a[i];
        while(a[i]*(sz+1)-sum>m){
            int temp=dq.front();dq.pop_front();
            sum-=temp;
            sz=dq.size();
        }
        dq.push_back(a[i]);
        maxn=max(maxn,sz+1);

    }
    write(maxn);
    return 0;
}
inline int read(){
    int sgn=0,ret=0,ch=getchar();
    while(!isdigit(ch)) sgn|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return sgn?-ret:ret;
}
inline void W(int x){
    if(x>9) W(x/10);
    putchar(x%10+'0');
    return;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    W(x);
    return;
}

//Oct31==Dec25?
