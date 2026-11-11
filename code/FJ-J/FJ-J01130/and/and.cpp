#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],m,f[200005],ans;
void dfs(int sum,int x){
	if(x==m){
		ans=max(ans,sum);
	}
	if(sum==0&&x!=0)return;
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
		dfs(x!=0?sum&a[i]:a[i],x+1);
		f[i]=0;
		}
	}
	
	
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	dfs(0,0);
	cout<<ans;
	return 0;
	}
	//能骗多少骗多少
	 
