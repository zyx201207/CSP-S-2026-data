#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,aa,b,bb;
void solve(){
  cin>>a>>aa>>b>>bb;
  if(a!=b){
    cout<<"0000";
    return;
  }
  a=aa;b=bb;
  if(a.substr(0,2)!=b.substr(0,2)){
    cout<<"1000";
    return;
  }
  if(a[2]<'D'!=b[2]<'D'){
    cout<<"1100";
    return;
  }
  if(a[2]<'D'&&b[2]<'D'){
    if(a[2]-b[2]==1||b[2]-a[2]==1)
        cout<<"1111";
    else
        cout<<"1110";
    return;
  }
  cout<<"1111";
}
signed main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  int t=1;
  //cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
