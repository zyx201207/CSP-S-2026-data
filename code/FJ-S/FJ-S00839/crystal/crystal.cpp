#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<numeric>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int n,l,r,mid,ans;
long long m;
long long power[500005],presum[500005];
int check(int x) {
  long long cnt=0x3F3F3F3F3F3F3F3Fll;
  for(int i=x;i<=n;i++)
    cnt=min(cnt,power[i]*x-presum[i]+presum[i-x]);
  return cnt<=m;
}
int main() {
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w+",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>power[i];
  sort(power+1,power+n+1);
  for(int i=1;i<=n;i++)
    presum[i]=presum[i-1]+power[i];
  ans=l=1,r=n;
  while(l<=r) {
    mid=(l+r)>>1;
    if(check(mid))
      ans=mid,l=mid+1;
    else  r=mid-1;
  }
  cout<<ans<<'\n';
}

