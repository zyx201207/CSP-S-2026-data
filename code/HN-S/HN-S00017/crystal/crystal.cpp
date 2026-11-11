#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m;
int a[N];
int sum[N];
signed main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
  int ans=0;
  for(int i=1;i<=n;i++){
    int lt=0,rt=i;
    while(lt+1<rt){
      int mid=(lt+rt)>>1;
      if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)rt=mid;
      else lt=mid;
    }ans=max(ans,i-rt+1);
  }cout<<ans;
  return 0;
}