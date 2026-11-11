#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m,a[N],mx=-1;
int b[N];
int pd(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			if(ans==0){
				ans=a[i];
			}else{
				ans=max(ans,a[i]);
			}
		}
	}
	mx=max(mx,ans);
}
void dfs(int t,int l){
	if(t==m){
		pd();
	}
	if(l>n){
		return;
	}
	dfs(t,l+1);
	b[l]=1;
	dfs(t+1,l+1);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1);
	cout<<mx;
	return 0;
}
