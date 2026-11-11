#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d;
int a[N];
int to[N];
int dis[N];
int cnt[N];
int ans=0;
void solve(int x){
  for(int i=1;i<=n;i++)dis[i]=1e18,cnt[i]=0;
  int now=x;
  queue<int> q;
  q.push(x);
  cnt[x]=1;
  dis[x]=0;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=now+1;i<=to[u];i++){
      if(dis[i]>dis[u]+1){
        dis[i]=dis[u]+1;
        q.push(i);
        cnt[i]=cnt[u];
      }else if(dis[i]==dis[u]+1){
        cnt[i]+=cnt[u];
        if(cnt[i]>2)now=i;
      }
    }
  }for(int i=1;i<=n;i++)ans+=(cnt[i]==2);
}
signed main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>c>>t;
  while(t--){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
      int lt=i,rt=n+1;
      while(lt+1<rt){
        int mid=(lt+rt)>>1;
        if(a[mid]-a[i]<=d)lt=mid;
        else rt=mid;
      }to[i]=lt;
      // cout<<to[i]<<" ";
      if(to[i]==i)to[i]=0;
    }
    for(int i=1;i<=n;i++){
      solve(i);
    }cout<<ans<<"\n";
  }
  return 0;
}//csps2027rp++