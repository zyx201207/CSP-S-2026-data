#include<iostream>
#include<algorithm>
#include<cstring>
// #include<vector>
using namespace std;
using ll=long long;
const int N=1e6+5;
int c,t;
int n;
ll d;
ll a[N];
ll sum[N];
int level[N];
int last[N];
int frm[N];
ll f[N];
// vector<int> faa[N];
void solve1(){
  ll ans=0;
  // for(int i=1;i<=n;i++) faa[i].clear();
  for(int i=1;i<=n;){
    // cerr<<"Now is "<<i<<'\n';
    int st=i;
    for(int j=i;j<=n;j++){
      level[i]=f[i]=0;
      frm[i]=0;
      sum[i]=0;
    }
    for(int j=i;j<=n;j++) last[j-i+1]=0;
    f[i]=level[i]=1;
    sum[i-1]=0;
    sum[i]=1;
    last[1]=i;
    int j=i+1;
    do{
      while(j<=n&&a[j]-a[i]<=d){
        level[j]=level[i]+1;
        frm[j]=i;
        last[level[j]]=j;
        j++;
      }
      if(level[i]!=1){
        int fa=frm[i];
        f[i]=sum[last[level[fa]]]-sum[fa-1];
        if(f[i]==2){
          // faa[i].push_back(st);
          ans++;
        }
        sum[i]=sum[i-1]+f[i];
      }
      i++;
    }while(i<j);
    // for(int j=st;j<=n;j++){
    //   cerr<<"[ "<<j<<" ]:\n"
    //       <<"level: "<<level[j]<<'\n'
    //       <<"f:     "<<f[j]<<'\n'
    //       <<"form:  "<<frm[j]<<'\n'
    //       <<"last:  "<<last[level[frm[j]]]<<'\n';
    //   cerr<<"===================================\n";
    // }
    i=st+1;
  }
  // for(int i=1;i<=n;i++){
  //   cerr<<"Now is: "<<i<<'\n';
  //   for(int e:faa[i]) cerr<<e<<' ';
  //   cerr<<"============\n";
  // }
  cout<<ans<<'\n';
}
int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  cin>>c>>t;
  while(t--){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    solve1();
  }
  cout.flush();
  fclose(stdin);
  fclose(stdout);
  return 0;
}