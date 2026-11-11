#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=0;
void dfs(int cnt,int num,int t){
	if(cnt==m){
		if(num>ans){
			ans=max(num,ans);
		}
		return;
	}
	for(int i=t;i<n;i++){
		if(cnt==0){
			num=a[i];
		}
		dfs(cnt+1,num&a[i],i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}

