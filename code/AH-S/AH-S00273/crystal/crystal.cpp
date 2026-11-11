#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long d[100010];
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long m;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  sort(a+1,a+n+1);
  for(int i=2;i<=n;i++){
    d[i]=a[i]-a[i-1];
  }
  d[n+1]=LLONG_MAX;
  long long l=1,r=1;
  long long sum=0,ans=0;
  for(;l<=n;l++){
    while(r<=n&&sum<=m-d[r]*(r-l+1)){
      sum+=d[r]*(r-l+1);
      r++;
    }
    ans=max(ans,r-l+1);
    sum-=a[r]-a[l];
  }
  cout<<ans<<endl;
  return 0;
}
