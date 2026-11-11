#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
const int N = 5e5+10;
int n,m;
int num[N];
int sum[N];
int bsearch(int i){
  int l = 1,r = i;
  while(l<=r){
    int mid = (l+r)>>1;
    int cost = (i-mid+1)*num[i]-sum[i]+sum[mid-1];
    if(cost>m)l=mid+1;
    else r=mid-1;
  }
  return i-l+1;
}
signed main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin>>n>>m;
  for(int i = 1;i<=n;i++){
    cin>>num[i];
  }
  sort(num+1,num+1+n);
  for(int i = 1;i<n;i++){
    sum[i]+=num[i];
    sum[i]+=sum[i-1];
  }
  int mmax = -1;
  for(int i = 1;i<=n;i++){
    mmax = max(bsearch(i),mmax);
  }
  cout<<mmax<<endl;
  return 0;
}
