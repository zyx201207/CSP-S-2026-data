#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define eb emplace_back
#define ep emplace
#define fr(a,b,c) for(int a = b;a <= c;a ++)
using namespace std;
const int N = 3000000;
int C,T,n,lr[N],st[N],dis[N],it,nw;
ll d,x[N],ans;
void work1();
void workA();
int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> C >> T;
  while(T --){
    cin >> n >> d;
    fr(i,1,n) cin >> x[i];
    if(C <= 10) work1();
    else if(C <= 12) workA();
  }
  return 0;
}
void work1(){
  ans = 0,it = 1;
  fr(i,1,n){
    while(it < n && x[it + 1] - x[i] <= d) it ++;
    lr[i] = it;
  }
  for(int i = n;i;i --){
    dis[i] = 0,st[i] = 1;
    for(int j = i - 1;j;j --){
      nw = min(lr[j],i),dis[j] = dis[nw] + 1;
      if(dis[nw] < dis[nw - 1]) st[j] = st[nw];
      else if(dis[nw - 1] < dis[nw - 2]) st[j] = st[nw] + st[nw - 1];
      else st[j] = 3;
      if(st[j] > 2) st[j] = 3;
      if(st[j] == 2) ans ++;
    }
  }
  printf("%lld\n",ans);
}
void workA(){
  if(n == 1){printf("0\n");return;}
  ll cnt = d / (x[2] - x[1]);
  if(2 * cnt > n || cnt < 2) printf("0\n");
  else printf("%lld\n",n - 2 * cnt + 1);
}
