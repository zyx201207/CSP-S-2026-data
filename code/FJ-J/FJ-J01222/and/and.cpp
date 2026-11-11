
#include<bits/stdc++.h>
using namespace std;//bao li dai ma
int n,m,a[200005],ans=INT_MIN;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int i,int step,int x){
//	cout<<i<<" "<<step<<" "<<x<<endl;
	if(step==m){
		ans=max(ans,x);
		return;
	}
	if(i>n) return;
	dfs(i+1,step,x);
	dfs(i+1,step+1,x&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	dfs(2,1,a[1]);
	cout<<ans;
return 0;}