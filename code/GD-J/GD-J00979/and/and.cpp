#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200200],ans=0;
void dfs(long long idx,long long sum,long long cnt){
	cout<<"idx = "<<idx<<"   "<<"cnt = "<<cnt<<"   ";
	cout<<"sum = "<<sum<<'\n';
	long long xq,xh;
	if (idx==n+1 || cnt==m){
		if (cnt==m){
			ans=max(ans,sum);
			cout<<'\n';
			cout<<"idx = "<<idx<<"   "<<"cnt = "<<cnt<<"   ";
			cout<<"sum = "<<sum<<"Ê±£º";
			cout<<"change £ºans = "<<ans<<'\n';
			return ;
		}else{
			return ;
		}
	}
	xq=sum;
	xh=(sum & a[idx]);
	if (sum==0){
		dfs(idx+1,a[idx],cnt+1);
		dfs(idx+1,0,cnt);
	}else{
		dfs(idx+1,xh,cnt+1);
		dfs(idx+1,xq,cnt);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
