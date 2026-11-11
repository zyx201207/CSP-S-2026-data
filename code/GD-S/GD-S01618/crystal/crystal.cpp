#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll sum[N];
int find(int i){
  int l=0,r=i-1;
  while(l<r){
    int mid=(l+r)/2;
    ll need=(i-mid)*a[i]-(sum[i]-sum[mid]);
    if(need<=m) r=mid;
    else l=mid+1;
  }
  return r;
}
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>a[i];
  sort(a+1,a+n+1);
  sum[0]=0;
  for(int i=1;i<=n;i++){
    sum[i]=sum[i-1]+a[i];
  }
  int ans=1;
  for(int i=2;i<=n;i++){
    int l=find(i);
    ans=max(ans,i-l);
  }
  cout<<ans;
  cout.flush();
  fclose(stdin);
  fclose(stdout);
  return 0;
}