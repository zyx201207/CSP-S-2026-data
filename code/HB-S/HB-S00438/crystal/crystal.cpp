#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500017];
signed main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
  cin >>n >>m;
  for(int i=1;i<=n;++i){
    cin>>a[i];
  }

  sort(a+1,a+n+1);

  int ans=1;
  for(int i=1;i<=n;++i){
    int b=10017,h=-b,s=0;
    for(int j=i;j<=n;++j){
      b= min(b,a[j]);
      h= max(h,a[j]);
      s += a[j];
      if((h-b+1)*j -s >  m){
        ans= max(ans,j-1);
        break;
      }
    }
  }
  cout << ans <<"\n";
}
