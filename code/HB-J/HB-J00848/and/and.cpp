#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,book[200005];
void dfs(int step,int sz){
	if(step==m+1){
		ans=max(ans,sz);
	}
	for(int i=1;i<=n;i++){
		if(book[a[i]]==0){
			book[a[i]]=1;
			if(step==1) dfs(step+1,a[i]);
			else dfs(step+1,a[i]&sz);
			book[a[i]]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}
