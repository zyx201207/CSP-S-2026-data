//GZ-S00411 jiangshiyu 蒋世宇
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
int n,m,ans=0;
int same=0;
int a[500005];


int addin(int x){
    int place=0;
    for(int i=1;i<=x;i++)
      place += a[x]-a[i];
  return place;

  }

int main () {
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
  cin>>n>>m;
  int r=1,l=n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a,a+1,a+n+1);
  //找目标数
  int mid=0;
   while(r<l){
    mid=r+(l-r)/2;
    if(addin(a[mid])>m) l=mid-1;
    if(addin(a[mid])<m) r=mid+1;
    if(addin(a[mid])==m) break;
   }
   //计算结果
   ans = mid;
   cout<<ans;
   return 0;


}
