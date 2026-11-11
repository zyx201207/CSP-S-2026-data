#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[200005];
bool vis[200005];
int f(int p,int num){
	if(p==0)return num;
	int mx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		mx=max(mx,f(p-1,num&a[i]));
		vis[i]=0;
		
	}
	return mx;
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
  	cin>>a[i];
  }
  ans=f(m,2147483647);
  cout<<ans;
  return 0;
}

