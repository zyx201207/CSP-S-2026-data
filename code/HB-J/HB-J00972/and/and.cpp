#include<bits/stdc++.h>
using namespace std;
struct node{
  int s;
  int logg;
  int logm;};
bool cmp(node a,node b){
  if(a.logg==b.logg){
    return a.s<b.s;
  }
  return a.logg<b.logg;
}
node a[200005];
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>a[i].s;
  }
  for(int i=1;i<=n;i++){
    a[i].logg=__log(a[i].s);
  }
  sort(a+1,a+n+1,cmp);
  int cnt=a[1].s;
  for(int i=2;i<=m;i++){
    cnt&=a[i].s;
  }
  cout<<cnt;
  return 0;
}//rp++
