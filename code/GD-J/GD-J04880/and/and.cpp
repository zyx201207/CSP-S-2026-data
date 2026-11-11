#include<iostream>
using namespace std;
#define ll long long
int n,m;
ll a[200005],ans;
void dfs(int sum,int x,int y){
	if(m==sum){
		ans=max(ans,x&a[y]);
		return ;
	}
	for(int i=0;i<n;i++){
		if(sum==0) dfs(sum+1,x+a[i],i+1);
		else dfs(sum+1,x&a[i],i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
