#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int kMaxN=5e5+100;

int n,l,r,ans;
ll m,a[kMaxN],q[kMaxN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++){
    q[i]=q[i-1]+a[i];
    l=1,r=i;
    for(;l<=r;){
      int M=l+r>>1;
      if((i-M+1)*a[i]-q[i]+q[M-1]<=m){
        r=M-1;
      }else{
        l=M+1;
      }
    }
    ans=max(ans,i-l+1);
  }
  cout<<ans;
	return 0;
}/*
我常常追忆过去
生命瞬间定格在脑海，我将背后的时间裁剪、折叠、蜷曲，揉捻成天上朵朵白云，云朵之间亦有分别
中间忘了
我该在哪里停留，我问我自己
//freopen
*/