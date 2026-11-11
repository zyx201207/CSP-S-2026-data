#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rp(i,a,b) for(int i=(a);i>=(b);--i)
const int N=1e6+5;
int cid,T,n,k,s[N],d[N],fa[N],m,a[N],fl[N];vector<int>e[N];
int P,D,sum;
inline void dfs(int x) {
  for(int y:e[x]) if(y!=fa[x]&&y!=P) d[y]=d[x]+1,fa[y]=x,dfs(y);
  return ;
}
inline void dfs(int x,int fa) {
  s[x]=0;
  for(int y:e[x]) if(y!=fa&&y!=P) {
    dfs(y,x);s[x]=max(s[x],s[y]+1);
  }
  if(s[x]>=D) ++sum;
  return ;
}
inline int work(int ds,int rt,int pv) {
  fr(i,1,n) d[i]=0;
  P=pv;D=ds;sum=0;
  d[rt]=0;fa[rt]=pv;dfs(rt);
  int fr=1;fr(i,2,n) if(d[i]>d[fr]) fr=i;
  d[fr]=fa[fr]=0;dfs(fr);
  int to=1;fr(i,1,n) if(d[i]>d[to]) to=i;
  if(d[to]<=2*ds) return 1;
  m=0;
  while(to) a[++m]=to,to=fa[to];
  rt=a[(m+1)/2];
  dfs(rt,0);
  return sum;
}
inline void dfs1(int x,int fa) {
  s[x]=0;
  for(int y:e[x]) if(y!=fa&&!fl[y]) dfs1(y,x),s[x]=max(s[y]+1,s[x]);
  if(s[x]>=D) ++sum;
  return ;
}
int lv[N];
inline bool ck(int mid) {
  if(n<=4000) {
    fr(x,1,n) for(int y:e[x]) if(y>x) {
      int s=work(mid,x,y)+work(mid,y,x);
      if(s<=k) return 1;
    }
  }
  else {
    d[1]=fa[1]=0;dfs(1);
    int rt=1;fr(i,2,n) if(d[i]>d[rt]) rt=i;
    d[rt]=fa[rt]=0;dfs(rt);
    int to=1;fr(i,1,n) if(d[i]>d[to]) to=i;
    m=0;
    while(to) a[++m]=to,to=fa[to];
    fr(i,1,n) fl[i]=0;
    fr(i,1,m) fl[a[i]]=1;
    D=mid;sum=0;
    fr(i,1,m) dfs1(a[i],0);
    int mn=n,fl=0,su=0,lst=0;
    fr(i,1,m) {
      if(s[a[i]]>=D) fl=1,lst=i;
      if(i>D) fl=1;
      su+=fl-(s[a[i]]>=D);
      while(lst<i&&i-lst+s[a[i]]>D) ++lst;
      lv[i]=su-(i-lst);
    }
    su=0;lst=m+1;fl=0;
    rp(i,m,2) {
      if(s[a[i]]>=D) fl=1,lst=i;
      if(i<=m-D) fl=1;
      su+=fl-(s[a[i]]>=D);
      while(lst>i&&lst-i+s[a[i]]>D) --lst;
      mn=min(mn,max(1,lv[i-1])+max(1,su-(lst-i)));
    }
    return mn+sum<=k;
  }
  return 0;
}
pair<int,int>pr[N];
mt19937 mt(20384);
inline void work() {
  scanf("%d%d",&n,&k);
  fr(i,1,n) e[i].clear();
  fr(i,1,n-1) {int x,y;scanf("%d%d",&x,&y);e[x].push_back(y);e[y].push_back(x);pr[i]={x,y};}
  if(k>=n) return puts("0"),void();
  if(n<=4000) {
    shuffle(pr+1,pr+n,mt);
    int ans=n;
    fr(i,1,n-1) {
      int x=pr[i].first,y=pr[i].second;
      if(work(ans-1,x,y)+work(ans-1,y,x)<=k) {
        int l=1,r=ans-1;
        while(l<=r) {
          int mid=(l+r)>>1;
          if(work(mid,x,y)+work(mid,y,x)<=k) r=mid-1;
          else l=mid+1;
        }
        ans=l;
      }
      if(ans==1) break;
    }
    printf("%d\n",ans);
    return ;
  }
  int l=1,r=n/2;
  while(l<=r) {
    int mid=(l+r)>>1;
    if(ck(mid)) r=mid-1;
    else l=mid+1;
  }
  printf("%d\n",l);
  return ;
}
int main() {
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  scanf("%d%d",&cid,&T);
  while(T--) work();
	return 0;
}