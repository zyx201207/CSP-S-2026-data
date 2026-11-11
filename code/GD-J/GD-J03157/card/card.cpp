#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define stg string
#define Cn const
#define ld long double
using namespace std;
int read() {
    int r=0,fl=1;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') fl=-fl;c=getchar();}
    while(c>='0'&&c<='9') {r=(r<<3)+(r<<1)+(c^48);c=getchar();}
    return r*fl;
}
int Max(int a,int b) {return a>b?a:b;}
int Min(int a,int b) {return a<b?a:b;}
Cn ld eps=1e-9;
Cn ll Inf=1e18;
Cn int N=5e5+5;
int n,m,a[N],tn[N],suf[N];
int s[N],fa[N];
int stk[N],top,sz[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) sz[i]=1;
    for(int i=n;i>=1;i--) {
       int x=a[i];
       if(!tn[x]) tn[x]=i;
       suf[i]=tn[x];
    }
    for(int i=1;i<=n;i++) {
        stk[++top]=i;
        if(suf[i]>i) {
        	while(top) fa[stk[top--]]=i;
		}
    }
    while(top) fa[stk[top--]]=n+1;
    fa[n+1]=n+1;
    for(int i=1;i<=n;i++) {
        sz[fa[suf[i]+1]]+=sz[i];
        s[suf[i]]+=sz[i],s[fa[suf[i]+1]]-=sz[i];
    }
    for(int i=1;i<=n;i++) s[i]+=s[i-1];
    for(int i=1;i<=m;i++) tn[i]=0;
    for(int i=1;i<=n;i++) tn[a[i]]+=s[i];
    for(int i=1;i<=m;i++) cout<<tn[i]<<" ";
    return 0;
}
